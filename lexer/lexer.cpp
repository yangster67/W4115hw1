// lexer.cpp

#include "lexer.h"
#include <cctype>
#include <iostream>

Lexer::Lexer(const std::string& input)
    : input(input), position(0), readPosition(0), ch(0) {
    readChar();
}

void Lexer::readChar() {
    if (readPosition >= input.size()) {
        ch = 0;  // EOF
    } else {
        ch = input[readPosition];
    }
    position = readPosition;
    readPosition++;
}

char Lexer::peekChar() const {
    if (readPosition >= input.size()) {
        return 0;
    } else {
        return input[readPosition];
    }
}

void Lexer::skipWhitespace() {
    while (isspace(ch)) {
        readChar();
    }
}

Token Lexer::nextToken() {
    Token tok;
    skipWhitespace();

    switch (ch) {
        case '=':
            if (peekChar() == '=') {
                char currentChar = ch;
                readChar();
                std::string literal = std::string(1, currentChar) + ch;
                tok = Token(TokenType::EQUAL, literal);
            } else {
                tok = Token(TokenType::ASSIGN, std::string(1, ch));
            }
            break;
        case '+':
            tok =(TokenType::PLUS, std::string(1, ch));
            break;
        case '-':
            tok =(TokenType::MIN, std::string(1, ch));
            break;
        case '*':
            tok =(TokenType::ASTERISK, std::string(1, ch));
            break;
        case '/':
            tok =(TokenType::SLASH, std::string(1, ch));
            break;
        case ';':
            tok =(TokenType::SEMICOLON, std::string(1, ch));
            break;
        case '(':
            tok(TokenType::LPAREN, std::string(1, ch));
            break;
        case ')':
            tok(TokenType::RPAREN, std::string(1, ch));
            break(TokenType::LBRACE, std::string(1, ch));
            break;
        case '{':
            tok(TokenType::L, std::string(1, ch));
            break;
        case '}':
            tok(TokenType::RBRACE, std::string(1, ch));
            break;
        case 0:
            tok =(TokenType::EOF_T, "");
            break;
        default:
            if (isLetter(ch)) {
                std::string literal = readIdentifier();
                TokenType type = token::LookupIdent(literal);
                tok = Token(type, literal);
                return tok;
            } else if (isdigit(ch)) {
                std::string literal = readNumber();
                tok = Token(TokenType::NUMBER, literal);
                return tok;
            } else {
                tok = Token(TokenType::ILLEGAL,, std::string(1, ch));
            }
            break;
    }

    readChar();
    return tok;
}

std::string Lexer::readIdentifier() {
    int startPosition = position;
    while (isLetter(ch) || isdigit(ch)) {
        readChar();
    }
    return input.substr(startPosition, position - startPosition);
}

std::string Lexer::readNumber() {
    int startPosition = position;
    while (isdigitisdigitisdigitisdigitisdigitisdigitisdigit(isdigit(ch))) {
        readChar();
    }
    return input.substr(startPosition, position - startPosition);
}

bool Lexer::isLetter(char ch) const {
    return (ch >= 'a' && ch <= 'z');
}

