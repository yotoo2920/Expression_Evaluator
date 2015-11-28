#include <iostream>

#include "Tokenizer.hpp"


int main(int argc, char const *argv[])
{

	Tokenizer parser;

	parser.parseInput(parser.getUserInput());

	vector<Tokens>* tokens = NULL;

	//if you found at least one syntax error, show errors and return
	vector<Tokens> errors = parser.getSyntaxErrorVector();

	// if error vector has at least one Invalid expression
	if(errors.size > 0)
	{
		std::cout << "Invalid expression entered." << std::endl;
		return;
	}

	//If the compiler reached at this point, it means that there were no errors - aka, my expression is correct
	tokens = parser.getTokenVector();

	CoreEvaluator * coreEvaluator = new CoreEvaluator();
	vector<Tokens>* reversePolishNotationTokensVector = coreEvaluator->ShuntingOperations(tokens);

	//create expression and evaluate

	// We can have an ExpressionHandler class, which is going to have a function that,
	// given reversePolishNotationTokensVector will

	// returns only one expression.

	// Then evaluate expression

	//-------------------------------------------------------------------------------------------------

	// testing and debbuging purpose
	if(!parser.wrong_user_input)
	{
		 tokens = parser.getTokenVector();



		for (int i = 0; i < tokens.size(); ++i)
		{
			std::cout << tokens.at(i) << " ";
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
