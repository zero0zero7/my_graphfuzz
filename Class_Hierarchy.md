## General Idea
1. XML -> Schema
    - For each struct, note the base and derived classes
    - For each struct, include the inherited methods
    - Recursive approach to process base classes before proceeding with derived classes
  
2.  Schema -> Mappings
    - Consumer: scopes that receive superclass obj => can also receive subclass obj
    - Producer: scopes that output subclass obj => "..." output superclass obj (unless superclass is abstract)
    - Initializer:  typetree that inits subclass can also init superclass



## Implementation

### 1. Adding Inherited Methods to Subclass' Section in schema.yaml
cli/gfuzz/commands/schema.py
- Made use of a few global dictionaries to keep track of classes and their methods
  - all methods ---  class_name : [func_id]  eg. Dog : [classDog_1a90u309u39, classAnimal_34nkvninkd]
  - methods implemented by current class ---  class_name : [func_id]   eg. Dog : [classDog_1a90u309u39, classDog_1fninvkvd]
  - parsed functions  ---  class/structName_funcid : {'ret': , 'name': , 'args': }

- use alloc_with_new: true as default. [note: generation of corresponding c++ code (for shims), already in original implementation in gen_cpp.py]

=> schema.yaml
- new syntax of `based`, `derived` in schema 
- inherited methods included 
- fixed inference of static methods to include enclosing class `Foo::`


### 2. Polymorphism for Consumers&Producers and Initializers
core/schema.hpp
- append consumer (producer) APIs of base (derived) classes to that of derived (base) classes

- Fuzzing with 1st test case: recursively build initializer typetrees for derived classes first, then proceed to the base classes
- Save this info in "cache.json" and "ndex.json"
  - ndex.json 
    - to keep track of initializers since each type can now have multiple initializers
    - `[[indices of initializers in cache.json for type0]], [indices of initializers in cache.json for type1], ...]`
- Throughout the rest of the fuzzing iteration: read from "cache.json" and  "ndex.json" to figure out which typetrees are initiailizers and finalizers of which struct


### 3. Casting object from derived to base to allow future access to object through base pointer
cli/gfuzz/commands/gen/cpp/gen_cpp.py 
- make_classpairs(id_name, derived)
  - recursively generate all pairs of based-derived => "classpairs.inc"
- make_shim_json(typ_dict: dict, scp_list: List)
  - generates json file containing input info of each shim
  - `{shim_number: [input type ids]}`
  - stringed code that will be used to do casting, includes:
    - function `build_cast_map`
    - template function `cast_helper` which references "classpairs.inc"

core/harness.cpp
- FuzzzerInitialize() ---  calls build_cast_map(), which is an added function in fuzz_exec.cpp, to instantiate the function template for each classpair and store the function pointer in the map
- LLVMFuzzerTestOneInput() --- in the for-loop used to call the shim for APIs in the graph, call the appropriate cast_helper (in fuzz_exec.cpp) based on prev & next shim



## Limitations
Abstract classes excluded from schema.yaml, so would not be able to show inheritance between abstract class and its concrete derived classes