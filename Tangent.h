#ifndef TAN_H
#define TAN_H

#include "Number.h"
#include "Cosine.h"
#include "Sine.h"
//#include "Divide.h"

class Tangent
{

private:

	Sine* sine;
	Cosine* cosine;
	//Divide* divide;

public:

	Tangent();
	~Tangent();

	Number* getTangent(Number*);
	/* data */
};

#endif 