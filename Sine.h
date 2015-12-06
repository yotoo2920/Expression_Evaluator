#ifndef SINE_H
#define SINE_H
#include "Number.h"
// #include "Power.h"
// #include "Add.h"
// #include "Subtract.h"
// #include "Factorial.h"

class Sine
{

private:

	unsigned long long factorial(int);

	double power(double, int);

	double radToDegrees(double);

	double degToRadian(double);

	double normalizeAngle(double);

	// Power* exponentiator;
	// Factorial* factorializer;
	// Add* adder;
	// Subtract* subtractor;

public: 

	Sine();

	~Sine();

	Number* getSine(Number*);
};

#endif 