#!/bin/bash

g++ -std=c++17 -o test_scanner test_scanner.cpp

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running tests..."
    echo "----------------------------------------"
    ./test_scanner
    echo "----------------------------------------"
else
    echo "Compilation failed."
fi
