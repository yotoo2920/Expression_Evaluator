#ifndef POWER_H
#define POWER_H
#include "Number.h"
#include "Multiply.h"

using namespace std;

class Power
{	
private:
	
	Multiply* mult;
	Number* pow;

public:
	Power();
	Number* getPower(Number* base, Number* exp);
};

#endif // POWER_H