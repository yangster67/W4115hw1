// lexer.h
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "../token/token.h"

class Lexer {
public:
    Lexer(const std::string& input);
    Token nextToken();

private:
    void readChar();
    char peekChar() const;
    void skipWhitespace();
    std::string readIdentifier();
    std::string readNumber();
    bool isLetter(char ch) const;

    std::string input;
    int position;     // current position in input (points to current char)
    int readPosition; // current reading position in input (after current char)
    char ch;          // current char under examination
};

#endif // LEXER_H
