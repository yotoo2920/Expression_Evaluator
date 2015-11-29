#ifndef NUMBER_H
#define NUMBER_H
<<<<<<< HEAD
#include<string>
#include"Expression.h"
=======

#include <string>
>>>>>>> 524d1514a7d3c7af05cb76e6803e458a22d511ec
#include <iostream>

#include "Expression.h"

using namespace std;
<<<<<<< HEAD
class number: public Expression
{
    public:
        number(int mants ,int exp):Expression(){
          mantissa=mants;
  exponent=exp;
  type="number";
        }
        //void power(int& ,int&);
         int mantissa;
    int exponent ;

       void printNumber(){
if (exponent>0)
{
int ten=10;
power(ten,exponent);

cout << mantissa/ten<<".";
int temp=ten;
while(temp/mantissa>9)
{
cout << "0";
temp=temp/10;
}
cout<<mantissa%ten;
}else cout << mantissa;
}

void power(int &mant ,int &power)
{
int newNumber=mant;
for (int i=0;i<power-1;i++)
{
mant=mant*newNumber;


}


}

protected:
    private:
};




=======

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


>>>>>>> 524d1514a7d3c7af05cb76e6803e458a22d511ec
#endif // NUMBER_H
