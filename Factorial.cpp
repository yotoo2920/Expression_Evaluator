#include <iostream>
#include "Factorial.h"
#include "Number.h"
#include <stdexcept>

using namespace std;

Factorial::Factorial()
{
	//empty constructor
}

Number* Factorial::getFactorial(Number* fact)
{
	magnitude = 1;
	for(int i = 1; i <= fact->mantissa; i++)
	{
		magnitude = magnitude * i;
	}
	decimal = 0;
	
	Number* zz = new Number(magnitude, decimal);
	return zz;
}
