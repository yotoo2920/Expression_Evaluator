#include <iostream>
#include "Sine.h"
#include "Tangent.h"
#include "Cosine.h"
#include "Number.h"
//#include "Divide.h"


Tangent::Tangent()
{

	this->sine = new Sine();
	this->cosine = new Cosine();
	//this->divide = new Divide();
}

Tangent::~Tangent(){}

Number* Tangent::getTangent(Number* value)
{

	// Tanget  == Sine / Cos 
	
	return new Number((this->sine->getSine(value)->asDouble())/(this->cosine->getCosine(value)->asDouble()));

}