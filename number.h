#ifndef NUMBER_H
#define NUMBER_H
#include<string>
#include"Expression.h"
#include <iostream>
using namespace std;
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




#endif // NUMBER_H
