#include <iostream>
#include "tokenizer.hpp"


int main(int argc, char const *argv[])
{
	
	Tokenizer parser;

	parser.parseInput(parser.getUserInput());

	if(!parser.wrong_user_input)
	{

		for (int i = 0; i < parser.getTokenVector().size(); ++i)
		{
			std::cout << parser.getTokenVector().at(i) << " ";
		}
		
	}

	std::cout << std::endl;

	for (int i = 0; i < parser.getSyntaxErrorVector().size(); ++i)
	{
		std::cout << parser.getSyntaxErrorVector().at(i) << " ";
	}

	std::cout << std::endl;

	return 0;
}