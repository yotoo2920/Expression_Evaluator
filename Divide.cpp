#include <iostream>
#include <stdexcept>
#include "Divide.h"
#include "Number.h"

using namespace std;

//Class performs the division of two numbers

Divide::Divide()
{
	tempValue = new Number();
}

Number* Divide::getDividend(Number* leftValue, Number* rightValue)
{

decimal = 0;
tempValue->mantissa = leftValue->mantissa;
tempValue->exponent = leftValue->exponent;

	// If denominator is zero, cannot do
	if(rightValue->mantissa == 0)
	{
		throw invalid_argument("You can't divide by zero");
	}
	// If denominator's exponent is larger than 0, multiply numerator to get mantissa
    if (rightValue->exponent>0)
    {
	    for (int i=0; i<rightValue->exponent;i++)
	    {

	    leftValue->mantissa*=10;

	    }
    }

    // Set magnitude  == numerator / denominator
	magnitude = leftValue->mantissa / rightValue->mantissa;

	// If when we divide, there is no remander, the decimal is 0
	if(leftValue->mantissa % rightValue->mantissa == 0)
	{
		decimal = 0;
	}

	// If remainder is not zero, find the decimals
	else
	{
		while(leftValue->mantissa % rightValue->mantissa != 0 && decimal < 5)
		{
			magnitude *= 10;

			leftValue->mantissa = (leftValue->mantissa % rightValue->mantissa) * 10;
			magnitude += leftValue->mantissa / rightValue->mantissa;
			decimal++;

		}
	}

	// If numerator has decimal value greater than zero, add number of decimal places
	if(leftValue->exponent > 0)
	{
		decimal += leftValue->exponent;
	}

	// Set left values mantissa and exponent
	leftValue->mantissa = tempValue->mantissa;
	leftValue->exponent = tempValue->exponent;

	Number* y = new Number(magnitude, decimal);

	return y;
}
