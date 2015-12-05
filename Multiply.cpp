#include <iostream>
#include "Multiply.h"
#include "Number.h"

using namespace std;

Multiply::Multiply()
{
	//empty constructor
}

Number* Multiply::getProduct(Number* leftValue, Number* rightValue)
{
	magnitude = leftValue->mantissa * rightValue->mantissa;
	decimal = leftValue->exponent + rightValue->exponent;

	Number* x = new Number(magnitude, decimal);
	return x;
}