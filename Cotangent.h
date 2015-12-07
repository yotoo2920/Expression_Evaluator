#ifndef COTANGENT_H
#define COTANGENT_H
#include "Number.h"
#include "Tangent.h"

class Cotangent
{

private: 

	Tangent* tangent;

public: 

	Cotangent();

	~Cotangent();

	Number* getCotangent(Number*);

};

#endif // COTANGENT