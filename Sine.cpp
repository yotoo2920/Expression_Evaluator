#include <iostream>
#include "Sine.h"
#include "Number.h"
#include "Power.h"
#include "Factorial.h"
#include "Add.h"
#include "Subtract.h"


#ifndef ABS
	#define abs(number) number*-1
#endif

Sine::Sine()
{
	this->exponentiator = new Power();
	this->factorializer = new Factorial();
	this->adder = new Add();
	this->subtractor = new Subtract();
}

Sine::~Sine(){}

Number* Sine::getSine(Number* value)
{ 

	// double to_get_sine_of = 0;
	// int decimal_value = 0;
	// double sine_of_number = 0;
	// int final_mantissa;


	//if exponent is less than 0, which means we have floating point number
	// in disguise, perform this 


		Number* to_return = new Number(0,0);

		// decimal_value = (this->power_calculator->getPower(new Number(10,0),
		// 				new Number(abs(value->exponent), 0)))->mantissa;

		// // Returns value with correct decimal placed 
		// //This is the number we wanna get the sine of 
		// to_get_sine_of = double(value->mantissa / decimal_value);

		// // Returns sine of number in non mantissa form. So with decimal approximation

		// sine_of_number = to_get_sine_of;

		bool is_subtracting = true;

		// //Presetting the sine calculation to 100 iterations
		// for (int i = 1; i <= 100; i+=2)
		// {

		// 	if(is_subtracting)
		// 	{
		// 		sine_of_number = sine_of_number - this->power_calculator->getPower(value, new Number(i,0))
		// 		is_subtracting = false;
		// 	}

		// 	else if(!is_subtracting)
		// 	{


		// 		is_subtracting = true;
		// 	}

		// 	sine_of_number = i this->factorial_calculator
		// }

		// // Returns the sine in mantissa form, no decimal in final mantissa 
		// final_mantissa = int((pow(10,abs(value->exponent)))*sine_of_number);

		// return new Number(final_mantissa,value->exponent); 

		for(int i = 1; i < 100; i+=2)
		{
			if(is_subtracting)
			{
				to_return = this->subtractor->getDifference(
					value, this->exponentiator->getPower(value, new Number(i,0))
					);

				is_subtracting = false;
			}

			else if(!is_subtracting)
			{
				to_return = this->adder->getSum(
					value, this->exponentiator->getPower(value, new Number(i,0))
					);

				is_subtracting = true;
			}

		}

		return to_return;

	}

	// //When exponent is greater than or equal to zero 
	// // Take sin of value in mantissa form 
	// new_value = sin(value->mantissa);

	// //cast into int and multiply this value by 10^5
	// final_mantissa = int(new_value * pow(10,5));

	// return new Number(final_mantissa, -5);
