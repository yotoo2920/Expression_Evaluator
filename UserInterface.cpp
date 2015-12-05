#include <iostream>

#include "UserInterface.h"
#include "Tokenizer.hpp"
#include "CoreEvaluator.h"
#include "Calculate.h"
#include "Number.h"

using namespace std;

void UserInterface::Test()
{
	Tokenizer parser;

	parser.parseInput(parser.getUserInput());

	vector<Token> TounSorted;

	//if you found at least one syntax error, show errors and return
	vector<Token> errors = parser.getSyntaxErrorVector();

	// if error vector has at least one Invalid expression
	if(errors.size() > 0)
	{
	std::cout << "Invalid expression entered." << std::endl;
	//return 0;
	}

	//If the compiler reached at this point, it means that there were no errors - aka, my expression is correct
	TounSorted = parser.getTokenVector();
	vector<Token>* unSorted = &TounSorted;

	CoreEvaluator* coreEvaluator = new CoreEvaluator();
	vector<Token*>* SortedVector = coreEvaluator->ShuntingOperations(unSorted);

	Calculate* C = new Calculate();
  C->getCalcultation(SortedVector);

	for (int i=0; i < SortedVector->size(); i++)
	{
	std::cout << SortedVector->at(i)->GetTokenStr();
	std::cout << " ";
	}
	std::cout << " " << std::endl;
}

void UserInterface::Menu(){
	std::cout << "Basics: "<< endl;

	std::cout << "1. Add/Substract/Multiplication/Division" << std::endl;
	std::cout << "\t Ex: 3 + 4 - 6 * 2 + 3/2" << std::endl;

	std::cout << "2. Negative numbers should always be in parentheses" << std::endl;
	std::cout << "\t Ex: 5 + (-3)" << std::endl;

	std::cout << "3. When Using functions" << std::endl;
	std::cout << "\t Ex: -sin(3) OR cos(4)" << std::endl;

	std::cout << "4. When Using Exponents" << std::endl;
	std::cout << "\t Ex: 3 + 4^3" << std::endl;

	std::cout << "5. Natural log" <<std::endl;
	std::cout << "\t Ex: log(3,2)" << std::endl;

	std::cout << "6. Root" << std::endl;
	std::cout << "\t Ex: " << std::endl;

	std::cout << "7. Factorial" << std::endl;
	std::cout << "\t Ex: 4 + 2!" << std::endl;

	std::cout << std::endl;

}
UserInterface::UserInterface(){

}
