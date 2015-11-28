#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <iostream>

#include "Expression.h"

using namespace std;

class Number
{
    public:
      void power(int& ,int&);
      void printNumber();

    private:
      int mantissa;
      int exponent;
};




#endif // NUMBER_H
