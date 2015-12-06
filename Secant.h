#ifndef SECANT_H
#define SECANT_H
#include "Number.h"
#include "Cosine.h"

class Secant
{

private: 

	Cosine* cosine;

public: 

	Secant();

	~Secant();

	Number* getSecant(Number*);

};

#endif // SECANT