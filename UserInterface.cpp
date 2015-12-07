#include <iostream>
#include <string>
#include "UserInterface.h"
#include "Tokenizer.hpp"
#include "CoreEvaluator.h"
#include "Calculate.h"
#include "Number.h"

using namespace std;

UserInterface::UserInterface()
{

}

void UserInterface::Test()
{

	Tokenizer parser;
	string input = parser.getUserInput();
	if(input.size() == 0) {
		cout<<"No expression entered"<<endl;
		return;
	}
	parser.parseInput(input);

	vector<Token> TounSorted;

	//if you found at least one syntax error, show errors and return
	vector<Token> errors = parser.getSyntaxErrorVector();

	// if error vector has at least one Invalid expression
	if(errors.size() > 0)
	{
	std::cout << "Invalid expression entered." << std::endl;
	return;
	//return 0;
	}

	//If the compiler reached at this point, it means that there were no errors - aka, my expression is correct
	TounSorted = parser.getTokenVector();
	vector<Token>* unSorted = &TounSorted;

	CoreEvaluator* coreEvaluator = new CoreEvaluator();
	vector<Token*>* SortedVector = coreEvaluator->ShuntingOperations(unSorted);
	if(!coreEvaluator->isValid) {
		return;
	}
	Calculate* C = new Calculate();
    C->getCalcultation(SortedVector);

	cout << endl;

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
	std::cout << "\t Ex: sin(4) OR cos(4) OR tan(4)" << std::endl;
	std::cout << "\t\t csc(4) OR sec(4) OR cot(4)"

	std::cout << "4. If using negative functions" << std::endl;
	std::cout << "\t Ex: -sin(1)" << std::endl;

	std::cout << "5. When Using Exponents" << std::endl;
	std::cout << "\t Ex: 3 + 4^3" << std::endl;

	std::cout << "6. Natural log" <<std::endl;
	std::cout << "\t Ex: ln(3)" << std::endl;

	std::cout << "7. Log" << std::endl;
	std::cout << "\t Ex: log(3,2)" << endl;
	std::cout << "\t Where 3 is the base" << std::endl;

	std::cout << "8. Root" << std::endl;
	std::cout << "\t Ex: root(4,2) " << std::endl;
	std::cout << "\t Where 2 is the index" << std::endl;

	std::cout << "9. Factorial" << std::endl;
	std::cout << "\t Ex: 4 + 2!" << std::endl;

	std::cout << "10. PI should be in capital letter" << std::endl;
	std::cout << "\t Ex: 2 * PI" << std::endl;

	std::cout << std::endl;

}

void UserInterface::Welcome()
{
	cout << endl;
	cout << "H = Help   OR" << "   O = Off" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;

	char choice;
	cin >> choice;
	if (cin.fail())
	{
		cout << "Wrong choice, try again please.";
		cin.clear();
	}
}
