#include <iostream>

#include "Tokenizer.hpp"
#include "CoreEvaluator.h"

using namespace std;

int main(int argc, char const *argv[])
{

	Tokenizer parser;

	parser.parseInput(parser.getUserInput());

	vector<Token>* unSorted;

	//if you found at least one syntax error, show errors and return
	vector<Token> errors = parser.getSyntaxErrorVector();

	// if error vector has at least one Invalid expression
	if(errors.size() > 0)
	{
		cout << "Invalid expression entered." << endl;
		return 0;
	}

	//If the compiler reached at this point, it means that there were no errors - aka, my expression is correct
	unSorted = &parser.getTokenVector();

	CoreEvaluator* coreEvaluator = new CoreEvaluator();
	vector<Token*>* SortedVector = coreEvaluator->ShuntingOperations(unSorted);

  for (int i=0; i < SortedVector->size(); i++)
	{
		cout << SortedVector->at(i)->GetTokenStr();
		cout << " ";
	}
	cout << " " << endl;

	//create expression and evaluate

	// We can have an ExpressionHandler class, which is going to have a function that,
	// given reversePolishNotationTokensVector will

	// returns only one expression.

	// Then evaluate expression


	return 0;
}
