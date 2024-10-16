#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "../token/token.h"
// Include your scanner implementation
// #include "scanner.h"

// Use the token namespace
using token::Token;
using token::TokenType;

// Function to compare expected and actual tokens
void compareTokens(const std::vector<Token>& expected, const std::vector<Token>& actual) {
    assert(expected.size() == actual.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        assert(expected[i].type == actual[i].type);
        assert(expected[i].literal == actual[i].literal);
    }
}
// Test function declarations
void test_program1();
void test_program2();
void test_program3();
void test_program4();
void test_program5();

int main() {
    test_program1();
    test_program2();
    test_program3();
    test_program4();
    test_program5();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

// Test Program 1
void test_program1() {
    std::string program = R"(
    int a = 5;
    int b = 10;
    int sum = a + b;
    )";

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "a"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::NUMBER, "5"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "b"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::NUMBER, "10"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "sum"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::IDENTIFIER, "a"),
        Token(TokenType::PLUS, "+"),
        Token(TokenType::IDENTIFIER, "b"),
        Token(TokenType::SEMICOLON, ";")
    };

    Scanner scanner;
    std::vector<Token> tokens = scanner.scan(program);

    compareTokens(expectedTokens, tokens);

    std::cout << "test_program1 passed" << std::endl;
}

// Test Program 2
void test_program2() {
    std::string program = R"(
    int x = 7;
    if (x == 7) {
        x = x - 1;
    }
    )";

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "x"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::NUMBER, "7"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::IF, "if"),
        Token(TokenType::LPAREN, "("),
        Token(TokenType::IDENTIFIER, "x"),
        Token(TokenType::EQUAL, "=="),
        Token(TokenType::NUMBER, "7"),
        Token(TokenType::RPAREN, ")"),
        Token(TokenType::LBRACE, "{"),
        Token(TokenType::IDENTIFIER, "x"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::IDENTIFIER, "x"),
        Token(TokenType::MINUS, "-"),
        Token(TokenType::NUMBER, "1"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::RBRACE, "}")
    };

    Scanner scanner;
    std::vector<Token> tokens = scanner.scan(program);

    compareTokens(expectedTokens, tokens);

    std::cout << "test_program2 passed" << std::endl;
}

// Test Program 3
void test_program3() {
    std::string program = R"(
    int n = 3;
    int result = 1;
    forn(i, n) {
        result = result * i;
    }
    )";

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TokenType::INT, "int"),
        Token(
