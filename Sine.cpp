#include <iostream>
#include "Sine.h"
#include "Number.h"

#define PI 3.14159265359 

Sine::Sine()
{

}

Sine::~Sine(){}

Number* Sine::getSine(Number* value)
{ 


		Number* to_return = new Number(0,0);

		double number = Sine::normalizeAngle(value->asDouble());

		// Create a new instance of number to use in the for loop
		double number_to_keep = number;

		bool is_subtracting = true;		

		// Iterate throught this foor loop utilizing Taylor Series == x - ( x^3 / 3! ) + ( x^5 / 5! ) - ( x^7 / 7! ) ... 
		// I have a bool to kepp count of the positive and negative part of the sum

		for(int i = 3; i <= 20; i = i + 2)
		{

			double power = Sine::power(number_to_keep,i);
			double factorial = Sine::factorial(i);

			if(is_subtracting)
			{
				
				number -= (power/factorial); 

				is_subtracting = false;

				continue;

			}

			if(!is_subtracting)
			{
				
				number += (power/factorial); 

				is_subtracting = true;

			}

		}

		return new Number(number);

	}

// Custom factorial class to hold long value 
unsigned long long Sine::factorial(int number)
{
	if(number == 1 || number == 0) return 1;

	else
	{ 
		return number * Sine::factorial(number - 1);
	}
}

// Custom power class to support double for sine
double Sine::power(double base ,int exponent)
{
	double power = 1;

    for (int i=0; i<exponent; i++)
    {
     	power=power*base;
    }

    return power;

}

// Need to crop the number for that is passed to sine, so convert from rad to degrees 
double Sine::radToDegrees(double radians)
{

	return radians * (180 / PI);

}

// Convert degrees to Radians 
double Sine::degToRadian(double degrees)
{

	return degrees * (PI / 180);
}

// normalize the angle by subtracting the angle of the given degree from above function 
double Sine::normalizeAngle(double angle)
{
	double temp_angle = Sine::radToDegrees(angle);
	
	while(temp_angle > 360)
	{
		temp_angle -= 360;
	}

	return degToRadian(temp_angle);
}




