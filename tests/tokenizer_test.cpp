#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>

// Define the token types
enum TokenType {
    KEYWORD,
    TYPE,
    SYMBOL,
    OPERATOR,
    NUMBER,
    IDENTIFIER
};

// Token structure
struct Token {
    TokenType type;
    std::string value;
    Token(TokenType t, const std::string& v) : type(t), value(v) {}
};

// Scanner class
class Scanner {
public:
    std::vector<Token> scan(const std::string& input);
};

// Scanner implementation
std::vector<Token> Scanner::scan(const std::string& input) {
    std::vector<Token> tokens;
    size_t pos = 0;
    size_t length = input.length();

    while (pos < length) {
        // Skip whitespace
        while (pos < length && isspace(input[pos])) pos++;
        if (pos >= length) break;

        // Handle identifiers, keywords, and types
        if (isalpha(input[pos])) {
            size_t start = pos;
            while (pos < length && (isalnum(input[pos]) || input[pos] == '_')) pos++;
            std::string word = input.substr(start, pos - start);

            // Check for KEYWORD
            if (word == "while" || word == "if" || word == "else" || word == "for" || word == "forn") {
                tokens.emplace_back(KEYWORD, word);
            }
            // Check for TYPE
            else if (word == "int" || word == "vector" || word == "ll" || word == "pair") {
                tokens.emplace_back(TYPE, word);
            }
            // Otherwise, IDENTIFIER
            else {
                tokens.emplace_back(IDENTIFIER, word);
            }
        }
        // Handle NUMBER
        else if (isdigit(input[pos])) {
            size_t start = pos;
            while (pos < length && isdigit(input[pos])) pos++;
            tokens.emplace_back(NUMBER, input.substr(start, pos - start));
        }
        // Handle SYMBOL
        else if (input[pos] == '(' || input[pos] == ')' || input[pos] == '{' || input[pos] == '}' || input[pos] == ';') {
            tokens.emplace_back(SYMBOL, std::string(1, input[pos]));
            pos++;
        }
        // Handle OPERATOR
        else if (input[pos] == '+' || input[pos] == '-' || input[pos] == '/' || input[pos] == '*' || input[pos] == '=') {
            if (input[pos] == '=' && pos + 1 < length && input[pos + 1] == '=') {
                tokens.emplace_back(OPERATOR, "==");
                pos += 2;
            } else {
                tokens.emplace_back(OPERATOR, std::string(1, input[pos]));
                pos++;
            }
        }
        // Unknown character
        else {
            std::cerr << "Unknown character: " << input[pos] << std::endl;
            pos++;
        }
    }
    return tokens;
}

// Test functions
void test_keyword();
void test_type();
void test_symbol();
void test_operator();
void test_number();
void test_identifier();

int main() {
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
    Scanner scanner;
    std::vector<std::string> keywords = {"while", "if", "else", "for", "forn"};
    for (const auto& kw : keywords) {
        auto tokens = scanner.scan(kw);
        assert(tokens.size() == 1);
        assert(tokens[0].type == KEYWORD);
        assert(tokens[0].value == kw);
    }
    std::cout << "test_keyword passed" << std::endl;
}

void test_type() {
    Scanner scanner;
    std::vector<std::string> types = {"int", "vector", "ll", "pair"};
    for (const auto& ty : types) {
        auto tokens = scanner.scan(ty);
        assert(tokens.size() == 1);
        assert(tokens[0].type == TYPE);
        assert(tokens[0].value == ty);
    }
    std::cout << "test_type passed" << std::endl;
}

void test_symbol() {
    Scanner scanner;
    std::vector<std::string> symbols = {"(", ")", "{", "}", ";"};
    for (const auto& sym : symbols) {
        auto tokens = scanner.scan(sym);
        assert(tokens.size() == 1);
        assert(tokens[0].type == SYMBOL);
        assert(tokens[0].value == sym);
    }
    std::cout << "test_symbol passed" << std::endl;
}

void test_operator() {
    Scanner scanner;
    std::vector<std::string> operators = {"+", "-", "/", "*", "=", "=="};
    for (const auto& op : operators) {
        auto tokens = scanner.scan(op);
        assert(tokens.size() == 1);
        assert(tokens[0].type == OPERATOR);
        assert(tokens[0].value == op);
    }
    std::cout << "test_operator passed" << std::endl;
}

void test_number() {
    Scanner scanner;
    std::vector<std::string> numbers =
