
import pathlib
from typing import Tuple
import yaml
import json

import bs4
from bs4 import BeautifulSoup as BS
import tqdm


from .cliopt import CLIOpt


# Global dictionary of all funcs
# class_name : [func_id]  eg. Dog : [classDog_1a90u309u39, classAnimal_34nkvninkd]
# all classes including abstract
# all public methods including inherited, including static, excluding pure virtual
cls_funcs = {}

# Global dictionary of funcs spec in current class
# class_name : [func_id]   eg. Dog : [classDog_1a90u309u39, classDog_1fninvkvd]
cls_curr = {}

# Global dictionary of parsed functions
# class/structName_funcid : (func_signature , {memset: 0, free: 0})
# parsed_static[id][0] => func signature
# parsed_static[id][1] => dictionary of weights
parsed_static = {}
parsed_nonstatic = {}

# Global list of abstract classes
abstr_cls = []

all_info = []


# read from  risky.json
try:
    f = open('risky.json')
    risky = json.load(f)
    f.close()
except FileNotFoundError:
    risky = None


def map_risky(curr_func: str) -> dict:
    global risky
    if risky == None:
        return {}
    weights = {}
    for op in risky.keys():
        involved = risky[op]
        if curr_func in involved:
            weights[op] = 1
        else:
            weights[op] = 0
    return weights


# def parse_function(tag: bs4.element.Tag) -> str:
def parse_function(tag: bs4.element.Tag):
    """Convert a function memberdef tag to a signature string."""

    ret = str(tag.find('type').text)
    name = tag.find('name').string
    args = tag.find('argsstring').string
    
    return f'{ret} {name}{args}'.strip(), name

# def parse_static_function(tag: bs4.element.Tag) -> str:
def parse_static_function(tag: bs4.element.Tag):
    """Convert a function memberdef tag to a signature string."""

    ret = str(tag.find('type').text)
    # name = tag.find('name').string
    defin = tag.find('definition').string
    # remove "static" and leading left whitespace
    defin = defin[len('static'):].lstrip()
    defin = defin[len(ret):].lstrip()
    args = tag.find('argsstring').string
    
    name = tag.find('name').string
    return f'{ret} {defin}{args}'.strip(), name


def parse_enum(tag: bs4.element.Tag, header: str) -> dict:
    name = str(tag.find('name').string)
    values = [
        str(x.find('name').string)
        for x in tag.find_all('enumvalue')
    ]

    return (f'enum_{name}', {
        'type': 'enum',
        'headers': [header],
        'name': name,
        'values': values
    })


def parse_typedef(tag: bs4.element.Tag, header: str) -> dict:
    # The name of the newly defined type.
    typ = str(tag.find('type').string)
    name = str(tag.find('name').string)

    return (f'typedef_{name}', {
        'type': 'typedef',
        'headers': [header],
        'value': typ,
        'name': name
    })


def extract_file(root: pathlib.Path, refid: str) -> Tuple[str, dict]:
    """Extract file information.
    
    """
    path = root / f'{refid}.xml'
    dat = BS(open(path, 'r'), features="lxml")

    compoundname = str(dat.find('compoundname').string)

    info = []

    for k in dat.find_all('memberdef', kind='enum'):
        info.append(parse_enum(k, header=compoundname))

    for k in dat.find_all('memberdef', kind='typedef'):
        info.append(parse_typedef(k, header=compoundname))

    # Bundle global functions by file so we can organize and filter them.
    file_info = {}
    file_info['type'] = 'file'
    file_info['name'] = compoundname
    file_info['headers'] = [
        str(k.string)
        for k in dat.find_all('includes')
    ]
    file_info['methods'] = [
        parse_function(k)
        for k in dat.find_all('memberdef', kind='function', prot='public')
    ]

    # Ignore files that have no global functions.
    if len(file_info['methods']) > 0:
        info.append((f'file_{compoundname}', file_info))

    global all_info
    all_info += info
    return
    # return info


def extract_struct(root: pathlib.Path, refid: str) -> Tuple[str, dict]:
    """Extract struct information.
    
    Returns (refid, info) where info contains:
    - type: "struct"
    - name: Name of the struct.
    - headers: A list of header files used by this struct.
    - methods: A list of function signatures.
    """
    path = root / f'{refid}.xml'
    dat = BS(open(path, 'r'), features="lxml")

    abstract = False 

    # each key:value pair -- refid : [base1, base2, ]
    # instead use, list of ambi func's name
    ambi_nonstatic = []
    ambi_static = []

    global all_info

    # Skip if already processed
    global cls_curr
    if str(dat.find('compoundname').string) in cls_curr:
        return None

    # Process parent classes first
    parents = []
    for parent in dat.find_all('basecompoundref'):
        parents.append(parent.string)
        if parent not in cls_curr: # yet to be processed base classes
            extract_struct(root, parent.attrs['refid'])

    info = {}
    info['type'] = 'struct'
    info['name'] = str(dat.find('compoundname').string)
    info['default_destructor'] = True
    info['headers'] = [
        str(k.string)
        for k in dat.find_all('includes')
    ]
    info['alloc_with_new'] = True # use new() instead of static_cast & calloc

    global parsed_nonstatic
    global parsed_static
    curr_funcs = dat.find_all('memberdef', kind='function', prot='public')
    func_ids = []
    for func in curr_funcs:
        func_id =  func.attrs['id']
        func_ids.append(func_id)
        if func.attrs['static'] == "no":
            func_sig, func_name = parse_function(func)
            class_func = "{clas_name}::{func}".format(clas_name=info['name'], func=func_name)
            weights = map_risky(class_func)
            parsed_nonstatic[func_id] = [func_sig, weights]
        elif func.attrs['static'] == "yes":
            func_sig, func_name = parse_static_function(func)
            class_func = "{clas_name}::{func}".format(clas_name=info['name'], func=func_name)
            weights = map_risky(class_func)
            parsed_static[func_id] = [func_sig, weights]
    cls_curr.update({info["name"]: func_ids})

    all_mems = dat.find('listofallmembers').find_all('member', prot='public')
    func_ids = []
    for mem in all_mems:
        # exclude non-func members
        id = mem.attrs['refid']
        struct_name = id.split('_', 1)[0] # could be "classChildA" or "structChildA"
        if struct_name[0:5] == 'class':
            struct_name = struct_name[5:]
        elif struct_name[0:6] == 'struct':
            struct_name = struct_name[6:]
        if id not in cls_curr[struct_name]:
            continue
        # exclude pure-virtual func
        if mem.attrs['virt'] == 'pure-virtual':
            abstract = True
            abstr_cls.append(info['name'])
            continue
        # exclude parent constructors
        nm = mem.find('name').string
        if nm in cls_curr:
            if nm != info['name']: # not constructor of current class
                continue
        # exclude all destructors
        if nm[0] == '~':
            if nm[1:] in cls_curr.keys():
                continue
        # handle ambiguity scope
        # dont add into cls_funcs and hence func_ids, add into local list for ambiguous funcs
        if "ambiguityscope" in mem.attrs:
            if id in parsed_static.keys():
                ambi_static.append(nm)
            elif id in parsed_nonstatic.keys():
                ambi_nonstatic.append(nm)
            continue
        func_ids.append(id)
    global cls_funcs
    cls_funcs.update({info["name"]: func_ids})

    # return None if abstract class
    if abstract:
        abstr_cls.append(info['name'])
        return None
    
    # Direct parent class names
    #  excludes abstract parents
    info['base'] = []
    info['methods'] = []
    info['static_methods'] = []
    for x in cls_funcs[info["name"]]:
        if x in parsed_nonstatic:
            info['methods'].append(parsed_nonstatic[x])
        elif x in parsed_static:
            info['static_methods'].append(parsed_static[x])
    # for each ambifunc, convert into func_1base1name, func_2base2name, ...
    for i in range(len(parents)):
        par = parents[i]
        if par not in abstr_cls:
            info['base'].append(str(par))
        for x in set(ambi_static):
            ext_name = x + "_" + str(i) + par + "*TODO*"
            info['static_methods'].append(ext_name)
        for x in set(ambi_nonstatic):
            ext_name = x + "_" + str(i) + par + "*TODO*"
            info['methods'].append(ext_name)
    # Direct derived class names
    info['derived'] = []
    for child in dat.find_all('derivedcompoundref'):
        info['derived'].append(str(child.string))

    all_info += [(f'struct_{info["name"]}', info)]
    return


def extract_all(root: pathlib.Path) -> dict:
    index = root / 'index.xml'
    dat = BS(open(index, 'r'), features="lxml")
    
    for k in tqdm.tqdm(dat.find_all('compound', kind='struct'), desc='Parsing structs...'):
        extract_struct(root, str(k['refid']))

    for k in tqdm.tqdm(dat.find_all('compound', kind='class'), desc='Parsing classes...'):
        extract_struct(root, str(k['refid']))

    for k in tqdm.tqdm(dat.find_all('compound', kind='file'), desc='Parsing files...'):
        extract_file(root, str(k['refid']))

    global all_info
    return {k:v for k,v in all_info}


def run_infer(args):
    try:
        info = extract_all(pathlib.Path(args.doxygen_xml))
    except:
        print('[!] Could not parse doxygen output. Make sure there is an ' \
              '"index.xml" file in the target directory.')
        return
    # print("b4 dump", yaml.safe_dump(info)) # to check contents of "info" without anchorpoints
    open(args.output, 'w').write(yaml.dump(info))
    print(f'[*] Generated a schema with {len([k for k in info])} items.')


COMMANDS = {
    'infer': run_infer,
}


def register(parser):
    sub = parser.add_subparsers(dest='schema_mode')

    infer_parser = sub.add_parser('infer', help='Infer a schema from Doxygen xml.')
    infer_parser.add_argument('doxygen_xml', help='Path to a folder containing Doxygen xml.')
    infer_parser.add_argument('output', help='Path to output *.yaml file.')


def execute(args):
    if args.schema_mode in COMMANDS:
        COMMANDS[args.schema_mode](args)
    else:
        return False


SchemaAPI = CLIOpt(
    'schema',
    'Schema subcommands.',
    register,
    execute
)
