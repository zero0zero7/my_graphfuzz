#!/bin/bash

gfuzz schema infer ./xml/ ./schema.yaml
gfuzz gen cpp schema.yaml .
clang++-16 -g -o fuzz_exec fuzz_exec.cpp -fsanitize=fuzzer,address -lprotobuf -lgraphfuzz
clang++-16 -o fuzz_write fuzz_write.cpp -fsanitize=fuzzer -lprotobuf -lgraphfuzz
