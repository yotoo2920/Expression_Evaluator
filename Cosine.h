#ifndef COSINE_H
#define COSINE_H
#include "Number.h"
#include "Sine.h"

class Cosine
{

private: 

	Sine* sine;

public: 

	Cosine();

	~Cosine();

	Number* getCosine(Number*);



};

#endif // COSINE_H