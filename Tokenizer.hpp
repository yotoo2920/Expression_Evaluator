#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <vector>
#include <string>

using namespace std;

class Tokenizer
{

private:
	vector<string> tokens;
	vector<string> syntax_errors;

public:

	vector<string> &getTokenVector();
	vector<string> &getSyntaxErrorVector();
	Tokenizer();
	~Tokenizer();
	string getUserInput();
	void parseInput(string);
	bool validateOperator(string);
	bool wrong_user_input;
	bool isParentheses(char);
	bool isParentheses(string);
	bool isOperator(char);
	bool isOperator(string);
	bool isNumber(string);
	bool isKeyword(string);

};

#endif
