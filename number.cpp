#include <iostream>
#include<number.h>
#include<string.h>

number::number(int mants, int exp )
{
  mantissa=mants;
  exponent=exp;
}

//---------------------------------------------------------------------------------------
void number::printNumber()
{
if (exponent>0)
{
int ten=10;
power(ten,exponent);
cout << ten <<endl;
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

//----------------------------------------
void number::power(int &mant ,int &power)
{
int newNumber=mant;
for (int i=0;i<power-1;i++)
{
mant=mant*newNumber;


}


}
