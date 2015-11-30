#ifndef ADD_H
#define ADD_H

#include "Number.h"

using namespace std;

class Add
{
	private:
		long long magnitude;
		int decimal;

	public:
		Add();
		Number* getSum(Number* leftValue, Number* rightValue);
};

#endif // ADD_H
