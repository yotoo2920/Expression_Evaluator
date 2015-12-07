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
	cout << "Invalid expression entered." << endl;
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

	if(!C->isValid) {
		return;
	}

	cout << " is the solution" << endl;
	cout << endl;

	// for (int i=0; i < SortedVector->size(); i++)
	// {
	// cout << SortedVector->at(i)->GetTokenStr();
	// cout << " ";
	// }
	// cout << " " << endl;
}

void UserInterface::Menu(){

	cout << "Basics: "<< endl;

	cout << "1. Add/Substract/Multiplication/Division" << endl;
	cout << "\t Ex: 3 + 4 - 6 * 2 + 3/2" << endl;

	cout << "2. Negative numbers should always be in parentheses" << endl;
	cout << "\t Ex: 5 + (-3)" << endl;

	cout << "3. When Using functions" << endl;
	cout << "\t Ex: sin(4) OR cos(4) OR tan(4)" << endl;
	cout << "\t\t csc(4) OR sec(4) OR cot(4)" << endl;

	cout << "4. If using negative functions" << endl;
	cout << "\t Ex: -sin(1)" << endl;

	cout << "5. When Using Exponents" << endl;
	cout << "\t Ex: 3 + 4^3" << endl;

	cout << "6. Natural log" <<endl;
	cout << "\t Ex: ln(3)" << endl;

	cout << "7. Log" << endl;
	cout << "\t Ex: log(3,2)" << endl;
	cout << "\t Where 3 is the base" << endl;

	cout << "8. Root" << endl;
	cout << "\t Ex: root(4,2) " << endl;
	cout << "\t Where 2 is the index" << endl;

	cout << "9. Factorial" << endl;
	cout << "\t Ex: 4 + 2!" << endl;

	cout << "10. PI should be in capital letter" << endl;
	cout << "\t Ex: 2 * PI" << endl;

	cout << endl;

}
