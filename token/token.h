// token.h

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <unordered_map>


enum class TokenType {
    // Special Tokens
    ILLEGAL,
    EOF_T,  // End of File

    // Identifiers + literals
    IDENTIFIER,  // variable names, function names, etc.
    NUMBER,      // numeric literals
    BANG,        // !
    DEBUG,       // DBG

    // Operators
    ASSIGN,    // =
    PLUS,      // +
    MINUS,     // -
    SLASH,     // /
    ASTERISK,  // *
    EQUAL,     // ==
    NOT_EQUAL, // !=
    LT,        // <
    GT,        // >

    // Delimiters
    SEMICOLON, // ;
    COMMA,     // ,

    LPAREN,    // (
    RPAREN,    // )
    LBRACE,    // {
    RBRACE,    // }

    //logical operators
    AND,        // &&
    OR,         // || 

    // Keywords
    WHILE,
    IF,
    ELSE,
    FOR,
    FORN,

    // Types
    INT,
    VECTOR,
    LL,
    PAIR,

    // Error Token
    ERROR
};

// Token structure
class Token {
public:
    TokenType type;
    std::string literal;

    Token(TokenType type, const std::string& literal) : type(type), literal(literal) {}
};

// Function to get the keywords map
inline const std::unordered_map<std::string, TokenType>& get_keywords() {
    static const std::unordered_map<std::string, TokenType> keywords = {
        {"while",  TokenType::WHILE},
        {"if",     TokenType::IF},
        {"else",   TokenType::ELSE},
        {"for",    TokenType::FOR},
        {"forn",   TokenType::FORN},
        {"int",    TokenType::INT},
        {"vector", TokenType::VECTOR},
        {"ll",     TokenType::LL},
        {"pair",   TokenType::PAIR},
        {"DBG",    TokenType::DEBUG}
        // Add other keywords if necessary
    };
    return keywords;
}

// Function to lookup identifiers and keywords
inline TokenType LookupIdent(const std::string& ident) {
    const auto& keywords = get_keywords();
    auto it = keywords.find(ident);
    if (it != keywords.end()) {
        return it->second;
    }
    return TokenType::IDENTIFIER;
}

#endif // TOKEN_H
