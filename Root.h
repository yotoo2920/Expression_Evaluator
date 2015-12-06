#ifndef ROOT_H
#define ROOT_H
#include "Add.h"
#include "Multiply.h"
#include "Power.h"
#include "Divide.h"
#include "Number.h"

using namespace std;

class Root
{
private:
	Add* a;
	Multiply* mult;
	Power* pow;
	Divide* div;
	Number* tempValue;
	Number* temp1;
	Number* temp2; 
	Number* temp3; 
	Number* temp4; 
	Number* x; 
	Number* y;
public:
	Root();
	Number* getRoot(Number* value, Number* rt);
};

#endif // ROOT_H
