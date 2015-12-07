#ifndef FACTORIAL_H
#define FACTORIAL_H
#include "Number.h"
#include "Root.h"
#include "Multiply.h"

using namespace std;

class Factorial
{
private:
	Root* sqrt;
	Multiply* mult;
	Number* temp;
	Number* temp1;
	Number* PI;
	Number* magnitude;
	Number* count;
public:
	Factorial();
	Number* getFactorial(Number* fact);
};

#endif //FACTORIAL_H
