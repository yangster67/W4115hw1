CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17
LEXER_OBJ = lexer.o
LEXER_TESTS_OBJ = lexer_tests.o
EXECUTABLE = run_tests

# Rule to build the lexer object
$(LEXER_OBJ): /lexel/lexer.cpp /lexer/lexer.h
	$(CXX) $(CXXFLAGS) -c lexer.cpp -o $(LEXER_OBJ)

# Rule to build the lexer_tests object
$(LEXER_TESTS_OBJ): /tests/lexer_tests.cpp /lexer/lexer.h
	$(CXX) $(CXXFLAGS) -c lexer_tests.cpp -o $(LEXER_TESTS_OBJ)

# Rule to link the executable
$(EXECUTABLE): $(LEXER_OBJ) $(LEXER_TESTS_OBJ)
	$(CXX) $(CXXFLAGS) $(LEXER_OBJ) $(LEXER_TESTS_OBJ) -o $(EXECUTABLE)

# Rule for cleaning up compiled files
clean:
	rm -f $(EXECUTABLE) $(LEXER_OBJ) $(LEXER_TESTS_OBJ)

# Default rule
all: $(EXECUTABLE)

.PHONY: clean
