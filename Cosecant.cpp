#include <iostream>
#include "Sine.h"
#include "Cosecant.h"
#include "Number.h"


Cosecant::Cosecant()
{

	this->sine = new Sine();

}

Cosecant::~Cosecant(){}

Number* Cosecant::getCosecant(Number* value)
{


		return new Number((1)/(this->sine->getSine(value)->asDouble()));

}