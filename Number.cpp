#include <iostream>
#include <string>
#include <sstream>

#include "Number.h"

//#include "Expression.h"
using namespace std;

Number::Number()
{
    ///empty constructor
}

///-------------------------------------------------------------------------------
void Number::power(int& mant ,int& power)
{
    int newNumber=mant;

    for (int i=0; i<power-1; i++)
    {
      mant=mant*newNumber;
    }

}

///------------------------------------------------------------------------------

/*Number::Number(string &strTo) {

        converStringToNumber(strTo);

         mantissa=mants;
        exponent=exp;
        type="number";
        }
        */
///------------------------------------------------------------------------------
Number::Number(int mants ,int exp )
{
  mantissa=mants;
  exponent=exp;
  reduceNumber();
}

///--------------------------------------------------------------------------------
void Number::printNumber()
{

  if (exponent>0)
  {
    int ten=10;
    power(ten,exponent);
	
    cout << mantissa/ten<<".";
    int temp=ten;		
	if(mantissa < 0)
	{
		mantissa = mantissa * -1;
	}
	
  while(temp/(mantissa%ten)>10)		//changed this from 9 to 10
  {
    cout << "0";
    temp=temp/10;
  }

  cout<<mantissa%ten;
  }
  else cout << mantissa;
}

///------------------------------------------------------------------------------------
void Number::converStringToNumber(string str)
{

  char c;
  int num1;
  int num2;
  int ten=10;

  if (str.find(".")==-1)
  {
    exponent=0;
  }
  else
  {
    exponent = str.length()-str.find(".")-1;
    str=str.substr(0,str.find("."))+str.substr(str.find(".")+1,str.length()-1);

  }

  for (int i=0; i<str.length();i++)
  {
    ten=10;
    c=str.at(i);
    num1=c-'0';

    num2=str.length()-i-1;

    if (i==str.length()-1)
    {
      ten=1;
    }
    power(ten,num2);
    num1=num1*ten;

    mantissa=mantissa+ num1;

  } // end the for

}

///--------------------------------------------------------------------------------
void Number::reduceNumber()
{
  while(exponent>4)
  {
    mantissa=mantissa/10;
    exponent--;
  }

  while (mantissa%10==0 && exponent > 0)
  {
    mantissa=mantissa/10;
    exponent--;
  }

}
