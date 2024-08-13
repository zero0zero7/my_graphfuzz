## Usage

Do the following as the first steps because the "risky.json" produced here is needed to generate the "schema.yaml"
```
cp my_graphfuzz/core/json.hpp <dir_storing_parser.cpp>
make
run
```
Then just follow the same instructions as in the original GraphFuzz. Replace "gfuzz" with "mygfuzz" and "lgraphfuzz" with "lmygraphfuzz"


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
        ./parser <path_to_target_lib_src_code> --
```
## Notes
- string not allowed in GraphFuzz, not included in their base_schema.yaml
- need to remove all .json .yaml files before re-generating them in event library src code changes
