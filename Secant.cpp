#include <iostream>
#include "Cosine.h"
#include "Secant.h"
#include "Number.h"

Secant::Secant()
{

	this->cosine = new Cosine();

}

Secant::~Secant(){}

Number* Secant::getSecant(Number* value)
{


		return new Number((1)/(this->cosine->getCosine(value)->asDouble()));

}