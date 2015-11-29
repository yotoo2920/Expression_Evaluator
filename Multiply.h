#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "Number.h"
#include "Expression.h"

using namespace std;

class Multiply
{
	private:
		long long leftValue;
		long long rightValue;
		int leftDec;
		int rightDec;

	public:
	    number result;
	    Multiply()
	    {

	    }
	    void setLeft(number);
			void setRight(number);
	    void getMagnitude();
	    void getDecimal();
	};

#endif // MULTIPLY_H
