#include <iostream>
#include "Subtract.h"
#include "Number.h"
using namespace std;

Subtract::Subtract()
{
	//empty constructor
}

Number* Subtract::getDifference(Number* leftValue, Number* rightValue)
{
	for(int i = 0; i < rightValue->exponent; i++)
	{
		leftValue->mantissa = leftValue->mantissa * 10;
	}

	for(int j = 0; j < leftValue->exponent; j++)
	{
		rightValue->mantissa = rightValue->mantissa * 10;
	}

	magnitude = leftValue->mantissa - rightValue->mantissa;
	decimal = leftValue->exponent + rightValue->exponent;

	Number* m = new Number(magnitude, decimal);
	return m;

}