#include <iostream>
#include "Sine.h"
#include "Tangent.h"
#include "Cotangent.h"
//#include "Divide.h"


Cotangent::Cotangent()
{

	this->tangent = new Tangent();
	//this->divide = new Divide();
}

Cotangent::~Cotangent(){}

Number* Cotangent::getCotangent(Number* value)
{

	// Inverse of tangent 
	
	return new Number((1)/(this->tangent->getTangent(value)->asDouble()));

}