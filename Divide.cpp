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
    if (rightValue->exponent>0)
    {
    for (int i=0; i<rightValue->exponent;i++)
    {
    leftValue->mantissa*=10;
    }


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
	cout << magnitude << endl;
	

	if(leftValue->exponent > 0)
	{
		decimal += leftValue->exponent;
	}
	cout << decimal << endl;
	Number* y = new Number(magnitude, decimal);
	return y;
}
