#ifndef NUMBER_H
#define NUMBER_H

#include <string>

using namespace std;

class Number
{
  public:
    Number();
    //Number(string &strTo);
    Number(double);
    Number(int ,int);
    int mantissa;
    int exponent ;
  string strToNum;
    void converStringToNumber(string str);
    void power(int&, int&);
    double power(double, int);
    void printNumber();
    void reduceNumber();
    double asDouble();

};

#endif // NUMBER_H
