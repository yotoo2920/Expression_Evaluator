#include <iostream>

#include "Add.h"

using namespace std;

Add::Add()
{
	//empty constructor
}

// Add method takes in two Number objects, left and right, and adds them

Number* Add::getSum(Number* leftValue, Number* rightValue)
{

	// Check right value exponent and multiply leftValue's mantissa by 10
	for(int i = 0; i < rightValue->exponent; i++)
	{
		leftValue->mantissa = leftValue->mantissa * 10;
	}

	// Do same thing as above to find the right values mantissa mult
	for(int j = 0; j < leftValue->exponent; j++)
	{
		rightValue->mantissa = rightValue->mantissa * 10;
	}

	// Set new magnitude (whole number part)
	// Set decimal part
	magnitude = leftValue->mantissa + rightValue->mantissa;
	decimal = leftValue->exponent + rightValue->exponent;

	Number* n = new Number(magnitude, decimal);

	return n;

}
