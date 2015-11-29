#include <iostream>

#include "Multiply.h"
#include "Number.h"

using namespace std;

void Multiply::setLeft(number lval)
{
    leftValue = lval.mantissa;
    leftDec = lval.exponent;
}

void Multiply::setRight(number rval)
{
    rightValue = rval.mantissa;
    rightDec = rval.exponent;
}

void Multiply::getMagnitude()
{
    result.mantissa = leftValue * rightValue;
}

void Multiply::getDecimal()
{
    result.exponent = leftDec + rightDec;
}
