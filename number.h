#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <iostream>

#include "Expression.h"

using namespace std;

class Number
{
    public:
      Number(long long int mants ,int expt);
      void power(long long &mant ,int &power);
      void printNumber();

    private:
      long long int mantissa;
      int exponent;
};


#endif // NUMBER_H
