#include <string>

#include "Number.h"

using namespace std;

Number::Number(long long int mants ,int expt)
{
  mantissa = mants;
  exponent = expt;
}

void Number::printNumber()
{
  if (exponent > 0)
  {
    long long ten = 10;
    power(ten,exponent);

    cout << mantissa/ten << ".";

    int temp = ten;
    while((temp/mantissa) > 9)
    {
        cout << "0";
        temp=temp/10;
    }
    cout << mantissa%ten;
  }
  else
    cout << mantissa;
}

void Number::power(long long &mant ,int &power)
{
  long long newNumber=mant;
  for (int i=0;i<power-1;i++)
  {
    mant=mant*newNumber;
  }
}
