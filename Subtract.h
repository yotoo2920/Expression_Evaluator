#ifndef SUBTRACT_H
#define SUBTRACT_H
#include "Number.h"
using namespace std;

class Subtract
{
private:
	long long magnitude;
	int decimal;
public:
	Subtract();
	Number* getDifference(Number* leftValue, Number* rightValue);
};

#endif // SUBTRACT_H