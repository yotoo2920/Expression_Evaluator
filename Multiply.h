#ifndef MULTIPLY_H
#define MULTIPLY_H
#include "Number.h"

using namespace std;

class Multiply
{
private:
	long long magnitude;
	int decimal;
public:
    Multiply();
    Number* getProduct(Number* leftValue, Number* rightValue);    
};

#endif // MULTIPLY_H