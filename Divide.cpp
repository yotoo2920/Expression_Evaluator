#include <iostream>
#include <stdexcept>
#include "Divide.h"
#include "Number.h"

using namespace std;

Divide::Divide()
{
	//empty constructor
}

Number* Divide::getDividend(Number* leftValue, Number* rightValue)
{
	if(rightValue->mantissa == 0)
	{
		throw invalid_argument("You can't divide by zero");
	}

	magnitude = leftValue->mantissa / rightValue->mantissa;

	if(leftValue->mantissa % rightValue->mantissa == 0)
	{
		decimal = 0;
	}

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

	Number* y = new Number(magnitude, decimal);
	return y;
}