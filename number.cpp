#include <string>

#include "Number.h"

using namespace std;

void printNumber()
{
  if (exponent > 0)
  {
    int ten=10;

    power(ten,exponent);

    cout << mantissa / ten << ".";

    int temp = ten;
    while((temp / mantissa) > 9)
    {
      cout << "0";
      temp = temp/10;
    }
    cout << mantissa%ten;
  }
  else cout << mantissa;
}

void power(int &mant ,int &power)
{
  int newNumber=mant;

  for (int i=0;i<power-1;i++)
  {
    mant=mant*newNumber;
  }

}
