#include <iostream>

#include "Add.h"

using namespace std;

Add::Add()
{
	//empty constructor
}

Number* Add::getSum(Number* leftValue, Number* rightValue)
{
	for(int i = 0; i < rightValue->exponent; i++)
	{
		leftValue->mantissa = leftValue->mantissa * 10;
	}

	for(int j = 0; j < leftValue->exponent; j++)
	{
		rightValue->mantissa = rightValue->mantissa * 10;
	}

	magnitude = leftValue->mantissa + rightValue->mantissa;
	decimal = leftValue->exponent + rightValue->exponent;

	Number* n = new Number(magnitude, decimal);

	return n;

}
