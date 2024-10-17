#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& input) : input(input), position(0), readPosition(0), ch(0) {
    readChar();
}

void Lexer::readChar() {
    if (readPosition >= input.length()) {
        ch = 0;
    } else {
        ch = input[readPosition];
    }
    position = readPosition;
    readPosition++;
}

char Lexer::peekChar() {
    if (readPosition >= input.length()) {
        return 0;
    } else {
        return input[readPosition];
    }
}

std::string Lexer::readIdentifier() {
    int startPosition = position;
    while (isLetter(ch)) {
        readChar();
    }
    return input.substr(startPosition, position - startPosition);
}

std::string Lexer::readNumber() {
    int startPosition = position;
    while (isDigit(ch)) {
        readChar();
    }
    return input.substr(startPosition, position - startPosition);
}

void Lexer::skipWhitespace() {
    while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
        readChar();
    }
}

bool Lexer::isLetter(char ch) {
    return std::isalpha(ch) || ch == '_';
}

bool Lexer::isDigit(char ch) {
    return std::isdigit(ch);
}

std::string charToString(char ch) {
    return std::string(1, ch);
}

Token Lexer::newToken(TokenType type, const std::string& literal) {
    return Token(type, literal);
}

Token Lexer::nextToken() {
    Token tok;
    skipWhitespace();
    switch (ch) {
        case '=':
            if (peekChar() == '=') {
                char currentCh = ch;
                readChar();
                std::string literal = std::string(1, currentCh) + std::string(1, ch);
                tok = newToken(TokenType::EQUAL, literal);
            } else {
                tok = newToken(TokenType::ASSIGN, charToString(ch));
            }
            break;
        case '+':
            tok = newToken(TokenType::PLUS, charToString(ch));
            break;
        case '-':
            tok = newToken(TokenType::MINUS, charToString(ch));
            break;
        case '!':
            if (peekChar() == '=') {
                char currentCh = ch;
                readChar();
                std::string literal = std::string(1, currentCh) + std::string(1, ch);
                tok = Token{TokenType::NOT_EQ, literal};
            } else {
                tok = newToken(TokenType::BANG, charToString(ch));
            }
            break;
        case '/':
            tok = newToken(TokenType::SLASH, charToString(ch));
            break;
        case '*':
            tok = newToken(TokenType::ASTERISK, charToString(ch));
            break;
        case '<':
            tok = newToken(TokenType::LT, charToString(ch));
            break;
        case '>':
            tok = newToken(TokenType::GT, ch);
            break;
        case ';':
            tok = newToken(TokenType::SEMICOLON, ch);
            break;
        case '(':
            tok = newToken(TokenType::LPAREN, ch);
            break;
        case ')':
            tok = newToken(TokenType::RPAREN, ch);
            break;
        case ',':
            tok = newToken(TokenType::COMMA, ch);
            break;
        case '{':
            tok = newToken(TokenType::LBRACE, ch);
            break;
        case '}':
            tok = newToken(TokenType::RBRACE, ch);
            break;
        case 0:
            tok.literal = "";
            tok.type = TokenType::EOF_T;
            break;
        default:
            if (isLetter(ch)) {
                tok.literal = readIdentifier();
                tok.type = LookupIdent(tok.literal);
                return tok;
            } else if (isDigit(ch)) {
                tok.type = TokenType::INT;
                tok.literal = readNumber();
                return tok;
            } else {
                tok = newToken(TokenType::ILLEGAL, ch);
            }
    }

    readChar();
    return tok;
}
