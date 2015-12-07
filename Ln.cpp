#include <iostream>
#include "Add.h"
#include "Multiply.h"
#include "Power.h"
#include "Divide.h"
#include "Number.h"
#include "Ln.h"
#include "Subtract.h"
#include <stdexcept>

using namespace std;

Ln::Ln()
{

}

Number* Ln::getLn(Number* value)
{
	digit2 = new Number();
	digit = 0;
	a = new Add();
	mult = new Multiply();
	pow = new Power();
	div = new Divide();
	sub = new Subtract();
	tempValue = new Number();
	temp1 = new Number();
	temp2 = new Number();
	temp3 = new Number();
	temp4 = new Number();
	dec = new Number();
	neg = new Number(-1, 0);
	ans = new Number(0, 0);
	one = new Number(1, 0);
	ln10 = new Number(23026, 4);

	tempValue->mantissa = value->mantissa;		//setting the temp value mantissa
	tempValue->exponent = value->exponent;		//setting the temp value exponent

	if(value->mantissa == 0)
	{
		throw invalid_argument("You cannot do the natural log of zero");
	}

	else if(value->mantissa == 1 && value->exponent == 0)
	{
		value->mantissa = 0;
		value->exponent = 0;
		return value;
	}
	else if(value->mantissa == 27183 && value->exponent == 4)
	{
		return one;
	}

	else
	{

		while(value->mantissa != 0)
		{
			value->mantissa = value->mantissa / 10;
			digit++;
		}

		digit2->mantissa = digit - value->exponent;
		value->mantissa = tempValue->mantissa;
		value->exponent = digit;
		dec = sub->getDifference(value, one);

		for(int n = 1; n < 250; n++)
		{

			Number* base = new Number(n, 0);
			Number* inc = new Number(n + 1,0);

			temp1 = pow->getPower(neg, inc);

			temp2 = div->getDividend(temp1, base);

			temp3 = pow->getPower(dec, base);

			temp4 = mult->getProduct(temp2, temp3);

			ans = a->getSum(ans, temp4);

			delete base;
			delete inc;
		}

		temp1 = mult->getProduct(digit2, ln10);
		ans = a->getSum(ans, temp1);
	}
	return ans;
}
