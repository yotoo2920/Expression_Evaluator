#include "Power.h"
#include "Number.h"

using namespace std;

Power::Power()
{
    //ctor
}

Number* Power::getPower(Number* leftValue, Number* pow)
{
	magnitude=1;
  	decimal = 0;
  	for (int i=0; i<pow->mantissa;i++)
  	{
		magnitude*= leftValue->mantissa;
		if (leftValue->exponent>0)
		{
  			decimal=leftValue->exponent+decimal;
		}

      	while(decimal>4)
      	{
		magnitude=magnitude/10;
		decimal--;
      	}

      	while(magnitude%10==0 && decimal > 0)
      	{
		magnitude=magnitude/10;
		decimal--;
      	}
	}

	Number* y = new Number(magnitude, decimal);
	return y;
}
