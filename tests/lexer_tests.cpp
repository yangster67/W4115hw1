#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "../token/token.h"
#include "../lexer/lexer.h"
// Include your scanner implementation


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
    std::string program = R"(
    int x = 7;
    if (x == 7) {
        x = x - 1;
    }
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
    std::string program = 
    "int x = 7;"
    "if (x == 7) {"
    "   x = x - 1;"
    "}";

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TYPE, "int"),
        Token(IDENTIFIER, "x"),
        Token(OPERATOR, "="),
        Token(NUMBER, "7"),
        Token(SYMBOL, ";"),
        Token(KEYWORD, "if"),
        Token(SYMBOL, "("),
        Token(IDENTIFIER, "x"),
        Token(OPERATOR, "=="),
        Token(NUMBER, "7"),
        Token(SYMBOL, ")"),
        Token(SYMBOL, "{"),
        Token(IDENTIFIER, "x"),
        Token(OPERATOR, "="),
        Token(IDENTIFIER, "x"),
        Token(OPERATOR, "-"),
        Token(NUMBER, "1"),
        Token(SYMBOL, ";"),
        Token(SYMBOL, "}")
    };

    Scanner scanner;
    // Call your scan function here
    std::vector<Token> tokens = scanner.scan(program);

    // Compare expected and actual tokens
    compareTokens(expectedTokens, tokens);

    std::cout << "test_program2 passed" << std::endl;
}

void test_program3() {
    std::string program = 
    "int n = 3;"
    "int result = 1;"
    "forn(i, n) {"
    "   result = result * i;"
    "}";

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TYPE, "int"),
        Token(IDENTIFIER, "n"),
        Token(OPERATOR, "="),
        Token(NUMBER, "3"),
        Token(SYMBOL, ";"),
        Token(TYPE, "int"),
        Token(IDENTIFIER, "result"),
        Token(OPERATOR, "="),
        Token(NUMBER, "1"),
        Token(SYMBOL, ";"),
        Token(KEYWORD, "forn"),
        Token(SYMBOL, "("),
        Token(IDENTIFIER, "i"),
        Token(ERROR, ","),
        Token(IDENTIFIER, "n"),
        Token(SYMBOL, ")"),
        Token(SYMBOL, "{"),
        Token(IDENTIFIER, "result"),
        Token(OPERATOR, "="),
        Token(IDENTIFIER, "result"),
        Token(OPERATOR, "*"),
        Token(IDENTIFIER, "i"),
        Token(SYMBOL, ";"),
        Token(SYMBOL, "}")
    };

    Scanner scanner;
    std::vector<Token> tokens = scanner.scan(program);

    // Compare expected and actual tokens
    compareTokens(expectedTokens, tokens);

    std::cout << "test_program3 passed" << std::endl;
}

void test_program4() {
    std::string program = R"(
    int y = 10
    if (y == 10) {
        y = y + 2;
    }
    )";

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TYPE, "int"),
        Token(IDENTIFIER, "y"),
        Token(OPERATOR, "="),
        Token(NUMBER, "10"),
        Token(ERROR, "Expected ';' after '10'"),
        Token(KEYWORD, "if"),
        Token(SYMBOL, "("),
        Token(IDENTIFIER, "y"),
        Token(OPERATOR, "=="),
        Token(NUMBER, "10"),
        Token(SYMBOL, ")"),
        Token(SYMBOL, "{"),
        Token(IDENTIFIER, "y"),
        Token(OPERATOR, "="),
        Token(IDENTIFIER, "y"),
        Token(OPERATOR, "+"),
        Token(NUMBER, "2"),
        Token(SYMBOL, ";"),
        Token(SYMBOL, "}")
    };

    Scanner scanner;
    std::vector<Token> tokens = scanner.scan(program);

    // Compare expected and actual tokens
    compareTokens(expectedTokens, tokens);

    std::cout << "test_program4 passed" << std::endl;
}

void test_program5() {
    std::string program = R"(
    int a = 5;
    if (a < 10) {
        a = a * 2;
    }
    )";

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TYPE, "int"),
        Token(IDENTIFIER, "a"),
        Token(OPERATOR, "="),
        Token(NUMBER, "5"),
        Token(SYMBOL, ";"),
        Token(KEYWORD, "if"),
        Token(SYMBOL, "("),
        Token(IDENTIFIER, "a"),
        Token(ERROR, "Unknown operator '<'"),
        Token(NUMBER, "10"),
        Token(SYMBOL, ")"),
        Token(SYMBOL, "{"),
        Token(IDENTIFIER, "a"),
        Token(OPERATOR, "="),
        Token(IDENTIFIER, "a"),
        Token(OPERATOR, "*"),
        Token(NUMBER, "2"),
        Token(SYMBOL, ";"),
        Token(SYMBOL, "}")
    };

    Scanner scanner;
    std::vector<Token> tokens = scanner.scan(program);

    // Compare expected and actual tokens
    compareTokens(expectedTokens, tokens);

    std::cout << "test_program5 passed" << std::endl;
}