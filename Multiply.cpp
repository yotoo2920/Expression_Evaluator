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
	// Multiply left value mantissa and right value mantissa (whole part)
	// Then set decimal by adding their exponents (decimal)
	magnitude = leftValue->mantissa * rightValue->mantissa;
	decimal = leftValue->exponent + rightValue->exponent;

	Number* x = new Number(magnitude, decimal);
	return x;
}
