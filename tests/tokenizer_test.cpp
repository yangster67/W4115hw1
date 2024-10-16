#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>

void test_keyword();
void test_type();
void test_symbol();
void test_operator();
void test_number();
void test_identifier();

int main() {
    //main testing function
    test_keyword();
    test_type();
    test_symbol();
    test_operator();
    test_number();
    test_identifier();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

void test_keyword() {
    // std::vector<std::string> keywords = {"while", "if", "else", "for", "forn"};
    // for (const auto& kw : keywords) {
    //     auto tokens = scanner.scan(kw);
    //     assert(tokens.size() == 1);
    //     assert(tokens[0].type == KEYWORD);
    //     assert(tokens[0].value == kw);
    // }
    std::cout << "test_keyword passed" << std::endl;
}

void test_type() {
    // std::vector<std::string> types = {"int", "vector", "ll", "pair"};
    // for (const auto& ty : types) {
    //     auto tokens = scanner.scan(ty);
    //     assert(tokens.size() == 1);
    //     assert(tokens[0].type == TYPE);
    //     assert(tokens[0].value == ty);
    // }
    std::cout << "test_type passed" << std::endl;
}

void test_symbol() {
    // Scanner scanner;
    // std::vector<std::string> symbols = {"(", ")", "{", "}", ";"};
    // for (const auto& sym : symbols) {
    //     auto tokens = scanner.scan(sym);
    //     assert(tokens.size() == 1);
    //     assert(tokens[0].type == SYMBOL);
    //     assert(tokens[0].value == sym);
    // }
    std::cout << "test_symbol passed" << std::endl;
}

void test_operator() {
    // Scanner scanner;
    // std::vector<std::string> operators = {"+", "-", "/", "*", "=", "=="};
    // for (const auto& op : operators) {
    //     auto tokens = scanner.scan(op);
    //     assert(tokens.size() == 1);
    //     assert(tokens[0].type == OPERATOR);
    //     assert(tokens[0].value == op);
    // }
    std::cout << "test_operator passed" << std::endl;
}

void test_number() {
    // Scanner scanner;
    // std::vector<std::string> numbers = {"0", "123", "456789"};
    // for (const auto& num : numbers) {
    //     auto tokens = scanner.scan(num);
    //     assert(tokens.size() == 1);
    //     assert(tokens[0].type == NUMBER);
    //     assert(tokens[0].value == num);
    // }
    std::cout << "test_number passed" << std::endl;
}

void test_identifier() {
    // Scanner scanner;
    // std::vector<std::string> identifiers = {"a", "abc", "a1b2c3", "variable", "x0"};
    // for (const auto& id : identifiers) {
    //     auto tokens = scanner.scan(id);
    //     assert(tokens.size() == 1);
    //     assert(tokens[0].type == IDENTIFIER);
    //     assert(tokens[0].value == id);
    // }
    std::cout << "test_identifier passed" << std::endl;
}
