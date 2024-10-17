#!/bin/bash

g++ -std=c++17 -o lexer_tests lexer_tests.cpp

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running tests..."
    echo "----------------------------------------"
    ./lexer_tests
    echo "----------------------------------------"
else
    echo "Compilation failed."
fi
