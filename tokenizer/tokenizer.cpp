#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "tokenizer.hpp"



Tokenizer::Tokenizer()
{
	this->wrong_user_input = false;
}

Tokenizer::~Tokenizer()
{

}

std::string Tokenizer::getUserInput()
{

	std::cout << "Input: ";
	std::string input;
	std::getline(std::cin, input);
	std::cout << std::endl;
	return input;

}

bool Tokenizer::isParentheses(char c) {
	if(c == '(' || c == ')') return true;
	else return false;
}

bool Tokenizer::isParentheses(std::string token) {
	if(token == "(" || token ==")") return true;
	else return false;
}

bool Tokenizer::isOperator(char c) {
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return true;
	else return false;
}

bool Tokenizer::isOperator(std::string token) {
	if(token == "+" || token == "-" || token == "*" || token == "/" || token == "^") return true;
	else return false;
}

bool Tokenizer::isKeyword(std::string token) {
	if(token == "sin" || token == "cos" || token == "tan" || token == "log" || token == "root") return true;
	else return false;
}

bool Tokenizer::isNumber(std::string token) {
	bool hasDecimal = false;
	for(int i = 0; i < token.size(); i++) {
		if(hasDecimal) {
			if(!std::isdigit(token[i])) return false;
		}
		else {
			if(!std::isdigit(token[i]) && token[i] != '.') return false;
			if(token[i] == '.') {
				if (i == token.size() - 1) return false;
				hasDecimal = true;
			}
		}
	}
	return true;
}

void Tokenizer::parseInput(std::string input)
{
// takes entire string that user inputs and breaks it using operators and parentheses as delimiters. (The delimiters are also stored as tokens). 
	std::string token = "";
	char c;
	for(int i = 0; i < input.size(); i++) {
		c = input[i];
		if(isOperator(c) || isParentheses(c)) {
			if(token != "") this->tokens.push_back (token);
			token = c;
			this->tokens.push_back (token);
			if (c == ')' && i < input.size() - 1 && !isOperator(input[i+1]) && !isspace(input[i+1])) this->tokens.push_back("*");
			token = "";
		}
		else if(i < input.size() - 1 && isdigit(c)) {
			token += c;
			if(input[i+1] == '(' || input[i+1] >= 'a' && input[i+1] <= 'z' ) {
				this->tokens.push_back(token);
				this->tokens.push_back("*");
				token = "";
			} 
		}
		else if(!std::isspace(c)){
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

std::vector<std::string> &Tokenizer::getTokenVector()
{
	return this->tokens;
}

std::vector<std::string> &Tokenizer::getSyntaxErrorVector()
{

	return this->syntax_errors;

}

bool Tokenizer::validateOperator(std::string value)
{

	if(isNumber(value) || isParentheses(value) || isKeyword(value) || isOperator(value)) return true;
	else return false;

}






