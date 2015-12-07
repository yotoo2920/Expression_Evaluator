#ifndef LN_H
#define LN_H
#include "Add.h"
#include "Multiply.h"
#include "Power.h"
#include "Divide.h"
#include "Subtract.h"
#include "Number.h"

using namespace std;

class Ln
{
private:
	Add* a;
	Multiply* mult;
	Power* pow;
	Divide* div;
	Subtract* sub;
	Number* tempValue;
	Number* temp1;
	Number* temp2;
	Number* temp3;
	Number* temp4;
	Number* dec;
	Number* neg;
	Number* ans;
	Number* one;
	Number* ln10;
	long long int digit;
	Number* digit2;
public:
	Ln();
	Number* getLn(Number* value);
};

#endif // LN_H
