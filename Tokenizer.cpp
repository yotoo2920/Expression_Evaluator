#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "Tokenizer.hpp"

using namespace std;

Tokenizer::Tokenizer()
{
	this->wrong_user_input = false;
}

Tokenizer::~Tokenizer()
{

}

string Tokenizer::getUserInput()
{

	std::cout << "Input: ";
	std::string input;
	std::getline(std::cin, input);
	return input;

}

bool Tokenizer::isParentheses(char c) {
	if(c == '(' || c == ')') return true;
	else return false;
}

bool Tokenizer::isParentheses(string token) {
	if(token == "(" || token ==")") return true;
	else return false;
}

bool Tokenizer::isOperator(char c) {
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == ',') return true;
	else return false;
}

<<<<<<< HEAD:tokenizer/tokenizer.cpp
bool Tokenizer::isOperator(std::string token) {
	if(token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == ",") return true;
=======
bool Tokenizer::isOperator(string token) {
	if(token == "+" || token == "-" || token == "*" || token == "/" || token == "^") return true;
>>>>>>> 5c343ac9d51ed00da6d082571cbd98fe2651a416:Tokenizer.cpp
	else return false;
}

bool Tokenizer::isKeyword(string token) {
	if(token == "sin" || token == "cos" || token == "tan" || token == "log" || token == "root") return true;
	else return false;
}

bool Tokenizer::isNumber(string token) {
	bool hasDecimal = false;
	for(int i = 0; i < token.size(); i++) {
<<<<<<< HEAD:tokenizer/tokenizer.cpp
		if(i == 0 && token[i] == '-') continue;
		else if(hasDecimal) {
			if(!std::isdigit(token[i])) return false;
=======
		if(hasDecimal) {
			if(!isdigit(token[i])) return false;
>>>>>>> 5c343ac9d51ed00da6d082571cbd98fe2651a416:Tokenizer.cpp
		}
		else {
			if(!isdigit(token[i]) && token[i] != '.') return false;
			if(token[i] == '.') {
				if (i == token.size() - 1) return false;
				hasDecimal = true;
			}
		}
	}
	return true;
}

<<<<<<< HEAD:tokenizer/tokenizer.cpp
void addToken(std:string token) {
	
}

void Tokenizer::parseInput(std::string input)
=======
void Tokenizer::parseInput(string input)
>>>>>>> 5c343ac9d51ed00da6d082571cbd98fe2651a416:Tokenizer.cpp
{
// takes entire string that user inputs and breaks it using operators and parentheses as delimiters. (The delimiters are also stored as tokens).
	string token = "";
	char c;
	for(int i = 0; i < input.size(); i++) {
		c = input[i];
		if(isOperator(c) || isParentheses(c)) {
			if(token != "") this->tokens.push_back (token);
			token = c;
			if(c == '-') {
				if(i > 0 && i < input.size()-2 && input[i-1] == '(') continue;
				else if(i < input.size() - 1 && islower(input[i+1])) {
					tokens.push_back("-1");
					tokens.push_back("*");
					token = "";
				} 
				else {
					tokens.push_back(token);
					token = "";
				}
			}
			else if (c == ')' && i < input.size() - 1 && !isOperator(input[i+1]) && !isspace(input[i+1])) {
				tokens.push_back(token);
				this->tokens.push_back("*");
				token = "";
			}  
			else {
				this->tokens.push_back (token);
				token = "";
			}
			
		}
		else if(i < input.size() - 1 && isdigit(c)) {
			token += c;
			if(input[i+1] == '(' || input[i+1] >= 'a' && input[i+1] <= 'z' ) {
				this->tokens.push_back(token);
				this->tokens.push_back("*");
				token = "";
			}
		}
		else if(!isspace(c)){
			token += c;
		}
	}
	if(token != "") this->tokens.push_back(token);
// if there is something to push, do this
if(!this->tokens.empty())
{
	for (int i = 0; i < this->tokens.size(); ++i) // iterate through vector
	{
		if(!Tokenizer::validateOperator(this->tokens.at(i))) // if one of string is not validate push to syntax error vector
		{
			this->syntax_errors.push_back(this->tokens.at(i)); // pushing to syntax error vector

			this->tokens.erase(this->tokens.begin()+i);

			this->wrong_user_input = true;
		}

	}

}

}

vector<string> &Tokenizer::getTokenVector()
{
	return this->tokens;
}

vector<string> &Tokenizer::getSyntaxErrorVector()
{

	return this->syntax_errors;

}

bool Tokenizer::validateOperator(string value)
{

	if(isNumber(value) || isParentheses(value) || isKeyword(value) || isOperator(value)) return true;
	else return false;

}
