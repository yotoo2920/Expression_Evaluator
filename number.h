#ifndef NUMBER_H
#define NUMBER_H
#include<string>

#include <iostream>
using namespace std;
class number
{
    public:
        number(int ,int);
        void power(int& ,int&);
         int mantissa;
    int exponent ;

       void printNumber();
    protected:
    private:

};

#endif // NUMBER_H
