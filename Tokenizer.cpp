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
	parenCheck = 0;
}

Tokenizer::~Tokenizer()
{
	
}

string Tokenizer::getUserInput()
{
	
	cout << "Input: ";
	string input = " ";
	getline(cin, input);
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
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == ',' || c == '!') return true;
	else return false;
}


bool Tokenizer::isOperator(std::string token) {
	if(token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "," || token == "!") return true;
	else return false;
}

bool Tokenizer::isKeyword(string token) {
	if(token == "sin" || token == "cos" || token == "tan" || token == "csc" || token == "sec" || token == "cot" || token == "log" || token == "ln" || token == "root" || token == "PI" || token == "e") return true;
	else return false;
}

bool Tokenizer::isNumber(string token) {
	bool hasDecimal = false;
	for(int i = 0; i < token.size(); i++) {
		if(token.size()> 1 && i == 0 && token[i] == '-') continue;
		else if(hasDecimal) {
			if(!std::isdigit(token[i])) return false;
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


void Tokenizer::addToken(string token) {
	if(isNumber(token)) {
		if(token[0] == '-') tokens.push_back(Token(NegValue,token));
		else {
			bool hasDecimal = false;
			for(int i = 0; i < token.size(); i++) {
				if(token[i] == '.') {
					hasDecimal = true;
					break;
				}
			}
			if(hasDecimal) tokens.push_back(Token(RealValue,token));
			else tokens.push_back(Token(IntValue,token));

		}
	}
	else if(token == "(")  {
		tokens.push_back(Token(OpenPar,token));
		parenCheck++;
	}
	else if(token == ")") {
		tokens.push_back(Token(ClosePar,token));
		parenCheck--;
	}
	else if (token == "sin") tokens.push_back(Token(sinFunc,token));
	else if(token == "cos") tokens.push_back(Token(cosFunc,token));
	else if(token == "tan") tokens.push_back(Token(tanFunc,token));
	else if(token == "csc") tokens.push_back(Token(cscFunc,token));
	else if(token == "sec") tokens.push_back(Token(secFunc,token));
	else if(token == "cot") tokens.push_back(Token(cotFunc,token));
	else if(token == "log") tokens.push_back(Token(LogFunc,token));
	else if(token == "ln") tokens.push_back(Token(lnFunc,token));
	else if(token == "root") tokens.push_back(Token(RootFunc,token));
	else if(token == "+") tokens.push_back(Token(PlusSign,token));
	else if(token == "-") tokens.push_back(Token(SubstSign,token));
	else if(token == "*") tokens.push_back(Token(MultSign,token));
	else if(token == "/") tokens.push_back(Token(DivSign,token));
	else if(token == "^") tokens.push_back(Token(PowerFunc,token));
	else if(token == ",") tokens.push_back(Token(Comma,token));
	else if(token == "!") tokens.push_back(Token(FactFunc,token));
	else if(token == "PI") tokens.push_back(Token(RealValue,"3.1415"));
	else if(token == "e") tokens.push_back(Token(RealValue,"2.7183"));
	else if(token =="-PI") tokens.push_back(Token(NegValue,"-3.1415"));
	else if(token == "-e") tokens.push_back(Token(NegValue,"-2.7183"));
	else tokens.push_back(Token(Error,token));

}

void Tokenizer::parseInput(string input)

{
// takes entire string that user inputs and breaks it using operators and parentheses as delimiters. (The delimiters are also stored as tokens).
	string token = "";
	char c;
	for(int i = 0; i < input.size(); i++) {
		c = input[i];
		if(isOperator(c) || isParentheses(c)) {
			if(token != "") addToken(token);
			token = c;
			if(c == '-') {
				if(i > 0 && i < input.size()-2 && input[i-1] == '(' && !isalpha(input[i+1])) continue;
				else if(i < input.size() - 1 && isalpha(input[i+1])) {
					addToken("-1");
					addToken("*");
					token = "";
				}
				else {
					addToken(token);
					token = "";
				}
			}
			else if (c == ')' && i < input.size() - 1 && !isOperator(input[i+1]) && !isspace(input[i+1]) && input[i+1] != ')') {
				addToken(token);
				addToken("*");
				token = "";
			}
			else {
				addToken(token);
				token = "";
			}
			
			if(parenCheck < 0) {
				wrong_user_input = true;
			syntax_errors.push_back(Token(ClosePar,")"));
			}

		}
		else if(i < input.size() - 1 && isdigit(c)) {
			token += c;
			if(input[i+1] == '(' || (input[i+1] >= 'a' && input[i+1] <= 'z') || (input[i+1] >= 'A' && input[i+1] <= 'Z')) {
				addToken(token);
				addToken("*");
				token = "";
			}
		}
		else if(!isspace(c)){
			token += c;
		}
	}
	if(token != "") addToken(token);
// if there is something to push, do this
if(!this->tokens.empty())
{
	for (int i = 0; i < this->tokens.size(); ++i) // iterate through vector
	{
		if(!Tokenizer::validateOperator(this->tokens.at(i).GetTokenStr())) // if one of string is not validate push to syntax error vector
		{
			this->syntax_errors.push_back(this->tokens.at(i)); // pushing to syntax error vector

			this->tokens.erase(this->tokens.begin()+i);

			this->wrong_user_input = true;
		}
		
		if(i == 0 || i == tokens.size() - 1) {
			if(isOperator(tokens[i].GetTokenStr())) {
				if(i == 0) {
					wrong_user_input = true;
					syntax_errors.push_back(tokens[i]);
				} 
				if(i == tokens.size() -1 && tokens[i].GetTokenStr() != "!") {
					wrong_user_input = true;
					syntax_errors.push_back(tokens[i]);
				}

			}
		}
		
		if(i < tokens.size() -1 && tokens[i].GetTokenStr() == "(" && tokens[i+1].GetTokenStr() == ")") {
			wrong_user_input = true;
			syntax_errors.push_back(tokens[i]);
		}
		
		if(i < tokens.size() -1 && isOperator(tokens[i].GetTokenStr()) && isOperator(tokens[i+1].GetTokenStr()) && tokens[i].GetTokenStr() != "!") {
			wrong_user_input = true;
			syntax_errors.push_back(tokens[i]);
		}
		
		if(i > 0 && i < tokens.size() - 1 && isOperator(tokens[i].GetTokenStr()) && tokens[i-1].GetTokenStr() == "(" && tokens[i+1].GetTokenStr() == ")") {
			wrong_user_input = true;
			syntax_errors.push_back(tokens[i]);
		}
		
		if(i > 0 && isOperator(tokens[i].GetTokenStr()) && tokens[i-1].GetTokenStr() == "(") {
			wrong_user_input = true;
			syntax_errors.push_back(tokens[i]);
		}
		
		if(i < tokens.size() - 1 && isOperator(tokens[i].GetTokenStr()) && tokens[i].GetTokenStr() != "!" && tokens[i+1].GetTokenStr() == ")") {
			wrong_user_input = true;
			syntax_errors.push_back(tokens[i]);
		}
		
		if(i< tokens.size() - 3 && (tokens[i].GetTokenStr() == "root" || tokens[i].GetTokenStr() == "log")) {
			for(int j = i; j < tokens.size(); j++) {
				if(tokens[j].GetTokenStr() == ",") break;
				else if(tokens[j].GetTokenStr() == ")") {
					wrong_user_input = true;
					syntax_errors.push_back(tokens[i]);
					break;
				}
			}
		}
		
	}
	if(parenCheck != 0) wrong_user_input = true;
	if(parenCheck > 0) syntax_errors.push_back(Token(OpenPar,"("));
	if(parenCheck < 0) syntax_errors.push_back(Token(ClosePar,")"));
}

}

vector<Token> Tokenizer::getTokenVector()
{
	return this->tokens;
}

vector<Token> Tokenizer::getSyntaxErrorVector()
{

	return this->syntax_errors;

}

bool Tokenizer::validateOperator(string value)
{

	if(isNumber(value) || isParentheses(value) || isKeyword(value) || isOperator(value)) return true;
	else return false;

}
