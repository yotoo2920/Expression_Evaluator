#include "Add.h"
#include "Divide.h"
#include "Multiply.h"
#include "Power.h"
#include "Number.h"
#include "Root.h"
#include <stdexcept>
#include <iostream>

using namespace std;


Root::Root()
{
	a = new Add();
	mult = new Multiply();
	pow = new Power();
	div = new Divide();
	tempValue = new Number();
	temp1 = new Number();
	temp2 = new Number();
	temp3 = new Number(1,0); 
	temp4 = new Number(); 
	x = new Number(2,0);		//the algorithm works best with base 2 here
	y = new Number();
}

Number* Root::getRoot(Number* value, Number* rt)
{
	tempValue->mantissa = value->mantissa;		//setting the temp value mantissa
	tempValue->exponent = value->exponent;		//setting the temp value exponent
	y->mantissa = rt->mantissa - 1;
	y->exponent = rt->exponent;
	temp1 = pow->getPower(x, rt);			
	
	if(value->mantissa == 1 && value->exponent == 0)	//nth root of 1 is 1	
	{
		return value;
	}

	else if(value->mantissa < 0)			//check if negative inside the root
	{
		throw invalid_argument("This gives a complex value!");
	}

	else if(value->mantissa == temp1->mantissa && value->exponent == temp1->exponent) //root = initial x
	{
		cout << "break code because you found the root already.\n";
		return value;
	}
	else
	{
		for(int i = 0; i < 10; i++)
		{
			value->mantissa = tempValue->mantissa;
			value->exponent = tempValue->exponent;

			temp1 = pow->getPower(x, y);			

			temp1 = div->getDividend(value, temp1);		

			temp2 = mult->getProduct(y, x);			

			temp1 = a->getSum(temp2, temp1);		
			
			temp4 = div->getDividend(temp3, rt);		
			
			x = mult->getProduct(temp4, temp1);		
		
		}
	}
	return x;

}
