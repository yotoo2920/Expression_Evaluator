#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <vector>
#include <string>

#include "Token.h"

class Tokenizer
{

private:
	std::vector<Token> tokens;
	std::vector<Token> syntax_errors;
	void addToken(std::string);

public:

	Tokenizer();
	~Tokenizer();

	std::string getUserInput();
	void parseInput(std::string);
	std::vector<Token> &getTokenVector();
	std::vector<Token> &getSyntaxErrorVector();
	bool validateOperator(std::string);
	bool wrong_user_input;
	bool isParentheses(char);
	bool isParentheses(std::string);
	bool isOperator(char);
	bool isOperator(std::string);
	bool isNumber(std::string);
	bool isKeyword(std::string);
};

#endif
