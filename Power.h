#ifndef POWER_H
#define POWER_H
#include "Number.h"
#include "Multiply.h"

using namespace std;

class Power
{	
private:
	Multiply* mult;
	Number* pow = new Number(1,0);
public:
	Power();
	Number* getPower(Number* base, int exp);
};

#endif // POWER_H