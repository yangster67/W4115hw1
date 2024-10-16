// main.cpp

#include <iostream>
#include <string>
#include <cstdlib>  // For getenv()
#include "repl.h"

int main() {
    // Get the current username
    std::cout << "Hello! This is the force_pp programming language!\n";
    std::cout << "Feel free to type in commands\n";
    repl::Start(std::cin, std::cout);

    return 0;
}
