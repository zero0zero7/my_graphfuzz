# Path Resolution

## Problem
Path of header file (for library source code) in fuzz_exec.cpp not accurate.
Requires manual revision.

1. "headers" section for each struct in auto-generated schema.yaml is derived from `<includes>` tag in the .xml file for that struct, which is the filename the struct is defined in
2. These filenames, without any path, will be carried over and included as header files in fuzz_exec.cpp

### Example
```
fuzz_dir
├── src
    ├── lib.h
    ├── x
    │   └── libx.h
    └── y
        └── lib.h
├── fuzz_exec.cpp
```

fuzz_exec.cpp would have 
```
#include "lib.h"
#include "libx.h"
```
-> Only 1 lib.h: For source files with repeated name, only 1 will be included


## Outline of Solution
Derive "headers" section for each struct in auto-generated schema.yaml from `<doxygen>.<compounddef>.<location>file`.
This gives relative file path "src/x/libx.h"

Code to patch:
- cli/gfuzz/commands/schema.py: extract_struct()
  - specifically, modify this 
    ```
    info['headers'] = [
            str(k.string)
            for k in dat.find_all('includes')
        ]
    ```
- cli/gfuzz/commands/gen/cpp/gen_cpp.py:make_exec_harness()
  - specifically, modify this to include ".hpp" files
    ```
    includes = [
        CPP_INCLUDE.format(header=h)
        for h in headers if h.endswith('.h')
    ]
    ```

Assumptions:
-  #include guards are appropriately implemented in the library (existing assumption in original graphfuzz implementation)
- fuzz_exec.cpp in same parent directory as src/
    Just make sure that `gfuzz gen cpp schema.yaml .` is done in src/'s parent directory ie. fuzz_dir in above example

