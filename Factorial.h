#ifndef FACTORIAL_H
#define FACTORIAL_H
#include "Number.h"

using namespace std;

class Factorial
{
private:
	long long magnitude;
	int decimal;
public:
	Factorial();
	Number* getFactorial(Number* fact);
};

#endif //FACTORIAL_H