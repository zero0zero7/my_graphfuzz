## Installation
1. remove /build directory
2. un-comment lines 10,11 in build.sh
3. run build.sh

## Usage

Do the following as the first steps because the "risky.json" produced here is needed to generate the "schema.yaml"
```
make
make run
cp risky.json <wherever_schema_infer_is_to_be_executed>
```
Then just follow the same instructions as in the original GraphFuzz. 
- replace path to target library source code in Doxyfile.template
- copy core/json.hpp to directory storing fuzz_exec.cpp, the casting shim needs it

For the test example, manually add `#include "lib.hpp"` to "fuzz_exec.cpp".\
<i> Ref "gen_cpp.py":make_exec_harness(), the auto-generated headers only include those that end with ".h", but in the example, the target lib src code ends with ".hpp" </i>


<u>Makefile for the static parser</u>
```
LLVMVER=/usr/lib/llvm-16
CLANG_INC=$(LLVMVER)/include/
CLANG_LIB=$(LLVMVER)/lib/
CXX=clang++-16

parser: parser.o
        $(CXX) -o $@ $< -L${CLANG_LIB} -lclang-cpp -lclang -lLLVM-16 -ltinfo \
        -rpath ${CLANG_LIB}

parser.o: parser.cpp
        $(CXX) -fno-rtti -O0 -I${CLANG_INC} -c $<

run:
        ./parser <path_to_target_lib_src_code> -- # might need additional cflags
```
## Notes
- Datatypes from std library not handled by GraphFuzz
  - not primitive type, thus not included in the base_schema.yaml
  - not class/structs defined in target library, thus not in schema.yaml
  - so it becomes an ~unknown datatype 
  - Either dont mutate them or write your own custom mutator for each of these datatypes
- need to remove all .json .yaml files before re-generating them in event library src code changes

Last minute code change for ambiguous conversion for non-virtual inheritance with common base classes
- Included another template parameter “SubB” to cast_helper(), which will contain:
  - The Base class (A) when there is no ambiguous conversion
  - Any direct derived class of the Base class (B or C) when there is ambiguous conversion
