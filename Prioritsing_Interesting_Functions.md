To identify functions that does **interesting / risky operations**, via Clang AST library

# Usage
### Makefile
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
        ./parser d.cc --
```

```
make
run
```


# Implementation

## Static Code Analysis
`parser.cpp`
Traverse AST tree, look out for function calls to interesting operations, get the caller-API

VisitCallExpr
1.  Get callee, and if calling an operation of interest (eg. memset),
2.  Checks its parent nodes recursively

RecursiveParent
- function template
- recursively read parent nodes until parent is of AST node type CXXMethodDecl, or until no more parents ie. reached root of AST


### Limitations
Overloaded functions in target library
- Current implementation obtains caller-API's name from AST to match to APIs listed in schema.yaml. 
  But API name alone is insufficient when there are more than one API with the same name (imagine function overloading)
- Ideally, we should be extracting the caller-API's name + function signature, and use these info to do the matching to ensure correctness
- extracting func signature from AST: https://github.com/Yunlongs/clang-function-prototype/tree/master 


## Piping Info Captured to Schema.yaml (c++ to python)

### Record in a JSON file
Static parser outputs a json file with a weights dictionary for each function.
json file read by `gen_cpp.py`

## Summary of New Code / Changes to Original Source Code
New files:
  - parser.cpp which generates "risky.json"
  - exmaple of "risky.json": `{"memset":["A::mset", "B::foo"]}`; => memset() operation is called by APIs A::mset and B::foo
gen_cpp.py:
- reads"risky.json"
Schema.hpp
- Add weights field to ScopeDef
- example of weights field for an API: `{"memset": 0}`; => no memset() called by this API else value would be "1"
Graph.hpp
- Additional representation of identified caller-APIs to be added to graph, depending on weights assigned
- Mutations involved:
  - SpliceOut
  - SpliceIn
  - LayerIndex
  - SwapEquivalent
  - TruncateConstructor
  - TruncateDestructor
  - Crosslink
  - ExtendConstructor
  - ExtendDestructor


# Future Work
## (Trivial) Allow user to decide 
### a) which operations:
Current implementation has "memset" hard-coded into VisitCallExpr()

TODO: 
- allow user to define which of these functions they want to target
- Perhaps,
  - memmove, memcpy, malloc, free, memcmp etc.
  - https://stackoverflow.com/questions/26558197/unsafe-c-functions-and-the-replacement
### b) importance (weight) of each operation:
Current implementation assigns binary weights

## Call graph
Build static call graph: Can make use of newly implemented VisitCallEXpr(), and recursiveParent()
1. Generalize VisitCallExpr() to spot clals to any function (not restrained to "memset")
2. Within VisitCallExpr(), trace to MethodDecl AST nodes using recursiveParent() (no change)
3. Build a directed graph, edge from caller to callee [methodDecl -- caller ; callExpr->getDirectCallee() -- callee]

Limitation: not comprehensive of all cases
- function templates
- indirect function calls (eg. through function pointer)

## Grouping Interesting Functions Together 
Instead of pinpointing individual functions, group multiple functions together based on the overarching vulnerability
- so instead of focusing on `functions`, this focuses on a `vulnerability`
- For example, 
  - for UAF vulnerability
  - static parser will now look for functions that does 1) memory allocation operations such as malloc() 2) free()
  - group these functions and their respective caller-API together
  - during graph mutation, if the graph consists of the caller-APIs identified above, then prioritize adding other caller-APIs in the same group (UAF) to the graph.

  Another group could be OOB access (malloc, memcpy, strcpy, ....)

