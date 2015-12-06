#ifndef POWER_H
#define POWER_H
#include "Number.h"

using namespace std;
class Power



{
private:
	long long int magnitude;
	long long int decimal;
public:
	Power();
	Number* getPower(Number* leftValue, Number* pow);
};
#endif // POWER_H
