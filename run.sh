#!/bin/bash

# Check if an argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 [init | run] dir/problem"
    exit 1
fi

if [[ "$1" == "run" ]]; then
    echo "Building $2.cpp"
    clang++ $2.cpp -std=c++17 -I./include
    echo "Running on $2.test"
    ./a.out < $2.test
elif [[ "$1" == "init" ]]; then
    cp templ.cpp $2.cpp
    touch $2.test
else
    echo "Command must be either init or run"
    exit 1
fi