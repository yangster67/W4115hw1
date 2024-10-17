#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "../token/token.h"
#include "../lexer/lexer.h"
// Include your lexer implementation


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
        int x = 7;
        int y = 10;
        int result = x + y;
    )";

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "x"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::NUMBER, "7"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "y"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::NUMBER, "10"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "result"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::IDENTIFIER, "x"),
        Token(TokenType::PLUS, "+"),
        Token(TokenType::IDENTIFIER, "y"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::EOF_T, "")
    };

    // Initialize Lexer
    Lexer lexer(program);

    // Get tokens
    std::vector<Token> tokens;
    Token tok = lexer.nextToken();
    while (tok.type != TokenType::EOF_T) {
        tokens.push_back(tok);
        tok = lexer.nextToken();
    }
    tokens.push_back(tok); // Add the EOF token

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "x"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::NUMBER, "7"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "y"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::NUMBER, "10"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "result"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::IDENTIFIER, "x"),
        Token(TokenType::PLUS, "+"),
        Token(TokenType::IDENTIFIER, "y"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::EOF_T, "")
    };

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
        Token(TokenType::RBRACE, "}"),
        Token(TokenType::EOF_T, "")
    };

    Lexer lexer(program);

    // Get tokens
    std::vector<Token> tokens;
    Token tok = lexer.nextToken();
    while (tok.type != TokenType::EOF_T) {
        tokens.push_back(tok);
        tok = lexer.nextToken();
    }
    tokens.push_back(tok); // Add the EOF token

    compareTokens(expectedTokens, tokens);

    std::cout << "test_program2 passed" << std::endl;
}

// Test Program 3
void test_program3() {
    std::string program =
        "int n = 3;"
        "int result = 1;"
        "forn(i, n) {"
        "   result = result * i;"
        "}";

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "n"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::NUMBER, "3"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "result"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::NUMBER, "1"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::FORN, "forn"),
        Token(TokenType::LPAREN, "("),
        Token(TokenType::IDENTIFIER, "i"),
        Token(TokenType::COMMA, ","),
        Token(TokenType::IDENTIFIER, "n"),
        Token(TokenType::RPAREN, ")"),
        Token(TokenType::LBRACE, "{"),
        Token(TokenType::IDENTIFIER, "result"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::IDENTIFIER, "result"),
        Token(TokenType::ASTERISK, "*"),
        Token(TokenType::IDENTIFIER, "i"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::RBRACE, "}"),
        Token(TokenType::EOF_T, "")
    };

    Lexer lexer(program);

    // Get tokens
    std::vector<Token> tokens;
    Token tok = lexer.nextToken();
    while (tok.type != TokenType::EOF_T) {
        tokens.push_back(tok);
        tok = lexer.nextToken();
    }
    tokens.push_back(tok); // Add the EOF token

    compareTokens(expectedTokens, tokens);

    std::cout << "test_program3 passed" << std::endl;
}

// Test Program 4
void test_program4() {
    std::string program = R"(
    int y = 10
    if (y == 10) {
        y = y + 2;
    }
    )";

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "y"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::NUMBER, "10"),
        Token(TokenType::ERROR, "Expected ';' after '10'"),
        Token(TokenType::IF, "if"),
        Token(TokenType::LPAREN, "("),
        Token(TokenType::IDENTIFIER, "y"),
        Token(TokenType::EQUAL, "=="),
        Token(TokenType::NUMBER, "10"),
        Token(TokenType::RPAREN, ")"),
        Token(TokenType::LBRACE, "{"),
        Token(TokenType::IDENTIFIER, "y"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::IDENTIFIER, "y"),
        Token(TokenType::PLUS, "+"),
        Token(TokenType::NUMBER, "2"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::RBRACE, "}"),
        Token(TokenType::EOF_T, "")
    };

    Lexer lexer(program);

    // Get tokens
    std::vector<Token> tokens;
    Token tok = lexer.nextToken();
    while (tok.type != TokenType::EOF_T) {
        tokens.push_back(tok);
        tok = lexer.nextToken();
    }
    tokens.push_back(tok); // Add the EOF token

    compareTokens(expectedTokens, tokens);

    std::cout << "test_program4 passed" << std::endl;
}

// Test Program 5
void test_program5() {
    std::string program = R"(
    int a = 5;
    if (a < 10) {
        a = a * 2;
    }
    )";

    // Expected tokens
    std::vector<Token> expectedTokens = {
        Token(TokenType::INT, "int"),
        Token(TokenType::IDENTIFIER, "a"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::NUMBER, "5"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::IF, "if"),
        Token(TokenType::LPAREN, "("),
        Token(TokenType::IDENTIFIER, "a"),
        Token(TokenType::LT, "<"),
        Token(TokenType::NUMBER, "10"),
        Token(TokenType::RPAREN, ")"),
        Token(TokenType::LBRACE, "{"),
        Token(TokenType::IDENTIFIER, "a"),
        Token(TokenType::ASSIGN, "="),
        Token(TokenType::IDENTIFIER, "a"),
        Token(TokenType::ASTERISK, "*"),
        Token(TokenType::NUMBER, "2"),
        Token(TokenType::SEMICOLON, ";"),
        Token(TokenType::RBRACE, "}"),
        Token(TokenType::EOF_T, "")
    };

    Lexer lexer(program);

    // Get tokens
    std::vector<Token> tokens;
    Token tok = lexer.nextToken();
    while (tok.type != TokenType::EOF_T) {
        tokens.push_back(tok);
        tok = lexer.nextToken();
    }
    tokens.push_back(tok); // Add the EOF token

    compareTokens(expectedTokens, tokens);

    std::cout << "test_program5 passed" << std::endl;
}
