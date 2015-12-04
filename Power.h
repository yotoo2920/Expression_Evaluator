#ifndef POWER_H
#define POWER_H
#include "Number.h"
#include "Multiply.h"

using namespace std;

class Power
{
private:
	long long magnitude;
	int decimal;
	

public:
	Power();
	Number* getPower(Number* leftValue, Number* pow);
};

#endif // POWER_H
