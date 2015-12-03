#ifndef SINE_H
#define SINE_H
#include "Number.h"
#include "Power.h"
#include "Add.h"
#include "Subtract.h"
#include "Factorial.h"

class Sine
{

private:

	Power* exponentiator;
	Factorial* factorializer;
	Add* adder;
	Subtract* subtractor;

public: 

	Sine();

	~Sine();

	Number* getSine(Number* value);
};

#endif 