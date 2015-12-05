#ifndef DIVIDE_H
#define DIVIDE_H
#include "Number.h"
using namespace std;

class Divide
{
private:
	long long magnitude;
	int decimal;
public:
	Divide();
	Number* getDividend(Number* leftValue, Number* rightValue);
};


#endif // DIVIDE_H
