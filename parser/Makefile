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
	./parser ./test/lib.hpp --

