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

void Tokenizer::parseInput(std::string input)
{
// takes entire string that user inputs and breaks it by spaces and puts it into a vector
	std::istringstream iss(input); 
	copy(std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>(),
		back_inserter(this->tokens));

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

	if (value.at(0)=='+'||
		value.at(0)=='-'||
		(value.at(0)=='r'&&
		value.at(1)=='t')||
		value.at(0)=='/'||
		value.at(0)=='*'||
		value.at(0)=='^'||
		value.at(0)=='0'||
		value.at(0)=='1'||
		value.at(0)=='2'||
		value.at(0)=='3'||
		value.at(0)=='4'||
		value.at(0)=='5'||
		value.at(0)=='6'||
		value.at(0)=='7'||
		value.at(0)=='8'||
		value.at(0)=='9'||
		value.at(0)==')'||
		value.at(0)=='('||
		(value.at(0)=='l'&& 
		 value.at(1)=='o'&& 
		 value.at(2) == 'g')||
		(value.at(0)=='s'&& 
		 value.at(1) == 'i'&& 
		 value.at(2) == 'n')||
		(value.at(0)== 'c'&&
			value.at(1)=='o'&&
			value.at(2)=='s')||
		(value.at(0)== 't'&&
			value.at(1)=='a'&&
			value.at(2)=='n') ||
		(value.at(0)== 'r'&&
			value.at(1)=='o'&&
			value.at(2)=='o'&&
			value.at(3)=='t'))
		{
			return true;
		}

		return false;

}






