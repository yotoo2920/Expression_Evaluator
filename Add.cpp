#include <iostream>
#include "Add.h"
#include "number.h"

using namespace std;

Add::Add()
{
	//empty constructor
}

number Add::getSum(number leftValue, number rightValue)
{
	for(int i = 0; i < rightValue.exponent; i++)
	{
		leftValue.mantissa = leftValue.mantissa * 10;
	}

	for(int j = 0; j < leftValue.exponent; j++)
	{
		rightValue.mantissa = rightValue.mantissa * 10;
	}

	magnitude = leftValue.mantissa + rightValue.mantissa;
	decimal = leftValue.exponent + rightValue.exponent;

	number n(magnitude, decimal);
	return n;

}