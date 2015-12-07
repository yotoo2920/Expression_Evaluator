#include <iostream>
#include "Factorial.h"
#include "Root.h"
#include "Multiply.h"
#include "Number.h"

using namespace std;

Factorial::Factorial()
{
	//empty constructor
}

Number* Factorial::getFactorial(Number* fact)
{
	sqrt = new Root();
	mult = new Multiply();
	count = new Number(0, 0);
	temp = new Number();
	temp1 = new Number(2, 0);
	PI = new Number(31415, 4);
	magnitude = new Number(1, 0);
	if(fact->exponent > 0)
	{
		while(fact->mantissa > 0)
		{
			magnitude->mantissa = magnitude->mantissa * fact->mantissa;
			fact->mantissa = fact->mantissa - 10;
			count->exponent = count->exponent + 1;		
		}
		temp = sqrt->getRoot(PI, temp1);
		magnitude = mult->getProduct(temp, magnitude); 
		magnitude->exponent = magnitude->exponent +  count->exponent;
	}
	else
	{
		for(int i = 1; i <= fact->mantissa; i++)
		{
			magnitude->mantissa = magnitude->mantissa * i;
		}
		magnitude->exponent = 0;
	}
	
	return magnitude;
}
