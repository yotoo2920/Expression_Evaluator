#ifndef COSECANT_H
#define COSECANT_H
#include "Number.h"
#include "Sine.h"

class Cosecant
{

private: 

	Sine* sine;

public: 

	Cosecant();

	~Cosecant();

	Number* getCosecant(Number*);

};

#endif // COSECANT