#!/bin/bash

make run_tests

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running tests..."
    echo "----------------------------------------"
    ./lexer_tests
    echo "----------------------------------------"
else
    echo "Compilation failed."
fi
