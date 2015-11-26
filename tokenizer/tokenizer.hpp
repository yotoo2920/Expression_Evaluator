#ifndef TOKENIZER_H_
#define TOKENIZER_H_
#include <vector>
#include <string>

class Tokenizer
{

private: 
	std::vector<std::string> tokens;
	std::vector<std::string> syntax_errors;

public:

	Tokenizer();
	~Tokenizer();

	std::string getUserInput();
	void parseInput(std::string);
	std::vector<std::string> &getTokenVector();
	std::vector<std::string> &getSyntaxErrorVector();
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