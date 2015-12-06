#include <iostream>
#include "Sine.h"
#include "Cosine.h"
#include "Number.h"

#define PI 3.14159265359 


Cosine::Cosine()
{

	this->sine = new Sine();

}

Cosine::~Cosine(){}

Number* Cosine::getCosine(Number* value)
{

	// Using Sine, we can implement Cosine by adding pi / 2 
	double value_to_pass = value->asDouble() + (PI/2);


	return new Number(this->sine->getSine(new Number(value_to_pass))->asDouble());

}