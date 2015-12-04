#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <iostream>
///#include"Expression.h"

using namespace std;

class Number///: public Expression
{
  //private:
  public: // these fields will be change to Private
    long long int mantissa;
    long long int exponent ;
    string strToNum;

  //public:
  	Number();
    //Number(string &strTo);
    Number(long long int ,long long int);
    //void power(int& ,int&);
    void converStringToNumber(string str);
    void power(long long int&, long long int&);
    void printNumber();
    void reduceNumber();

};

#endif // NUMBER_H
