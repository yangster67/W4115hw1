# Force_pp Fall 2024 W4115hw1

### Team:
Kevin Yang; ky2488
Dale Yu; dy2446

## Installation Steps
Needs GCC installed to compile in c++17.

To run tests on Linux/Mac:
./run_tests.sh

To build and lex any file:
1. make main
2. ./main <file> 


# Homework 1 Components

## Language Components
KEYWORD = while | if | else | for | forn | 
TYPE = int | vector | ll | pair | 
SYMBOL = ( | ) | { | } | ;
OPERATOR = + | - | / | * | = | ==
NUMBER = [0-9]+
IDENTIFIER = [a-z][a-z|0-9]*

#### DFA 
We have the DFA rendered using graphviz and it is in the `/DFA`

*How to create the DFA*
- run the command `dot -Tpng dfa.gv -o dfa.png` 
Here is our DFA that our lexing algorithm is built on:
![DFA picture](/DFA/dfa.png)

## Lexing Algorithm
Most of the time, the symbol type can be deduced from the first character, so it looks at that first and then does maximal munch to see how much we can take per word. 

## Shell Testing Scripts
testing scripts are found in `/tests`

##### References 
Collection of popular macros in comp programming: https://gist.github.com/abinashmeher999/e5993d17e9d25227cbe3#file-comp_macros-h-L3
