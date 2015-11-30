#ifndef ADD_H
#define ADD_H
#include "number.h"

using namespace std;

class Add
{
private:
	long long magnitude;
	int decimal;
public:
	Add();
	number getSum(number leftValue, number rightValue);
};

#endif // ADD_H