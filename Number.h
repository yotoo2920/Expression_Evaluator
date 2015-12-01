#ifndef NUMBER_H
#define NUMBER_H

#include<string>
#include <iostream>

///#include"Expression.h"

using namespace std;

class Number///: public Expression
{
public:
  int mantissa=0;
    int exponent ;
    string strToNum;

    public:
        Number(string  );
        Number(int ,int);
        void power(int& ,int&);
void converStringToNumber(string& str);
void power(int&  ,int);
void printNumber();
void reduceNumber();

};

#endif // NUMBER_H
