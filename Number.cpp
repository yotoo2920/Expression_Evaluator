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

Number::Number(long long int mants ,long long int exp )
{
  mantissa=mants;
  exponent=exp;
  reduceNumber();
}

Number::Number(double number)
{
  // Make number object from double
  // Method overloading to enter a double into this constructor
  // This will convert the number to a string and find  a "." to truncate

  std:string number_as_string = std::to_string(number);

   std::string truncated_number = "";

  // If value as string is greater than 15, crop it

   if(number_as_string.size() > 15)
   {

     for (int i = 0; i < 15; ++i)
     {

       truncated_number += number_as_string.at(i);
     }
   }
   else truncated_number = number_as_string;


   unsigned whole_number_count = 0;
   unsigned decimal_number_count = 0;
   bool found_dot = false;

   // Find the whole number part and the decimal part of the number, and count
   for (int i = 0; i < truncated_number.size(); ++i)
   {
     if(truncated_number.at(i) == '.')
     {
       found_dot = true;
       continue;
     }

     if(!found_dot) whole_number_count += 1;

     if(found_dot) decimal_number_count += 1;
   }

   int exponent_value = (truncated_number.size() - whole_number_count - 1);

   std::string mantissa_as_string = "";

   for (int i = 0; i < truncated_number.size(); ++i)
   {
     if(truncated_number.at(i) != '.')
     {
       mantissa_as_string += truncated_number.at(i);
     }
   }

   int mantissa_to_return = atoi(mantissa_as_string.c_str());

   this->mantissa = mantissa_to_return;
   this->exponent = exponent_value;

}

void Number::power(int& mant ,int& power)
{
    int newNumber=mant;

    for (int i=0; i<power-1; i++)
    {
      mant=mant*newNumber;
    }

}



void Number::printNumber()
{


   std::cout << Number::asDouble();

  // below does not print a negative when calling printNumber(), especially when using Sine

  // if (exponent>0)
  // {
  //   int ten=10;
  //   power(ten,exponent);
  //   cout << mantissa/ten<<".";
  //   int temp=ten;
  // if (mantissa<0)
  // {
  //   mantissa*=-1;
  // }
  // while(temp/(mantissa%ten)>9)
  // {
  //   cout << "0";
  //   temp=temp/10;
  // }
  //   cout<<mantissa%ten;
  // }
  // else cout << mantissa;

}

void Number::converStringToNumber(string str)
{
  mantissa=0;
  exponent=0;
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

double Number::power(double base ,int exponent)
{

  // this is another method overload to return as a double, useful for Sin.cpp
  // Is same thing as above but instead of void, it is double

  double power = 1;

    for (int i=0; i<exponent; i++)
    {
      power=power*base;
    }

    return power;

}


double Number::asDouble()
{
  // returns number as double

  if (exponent>0)
  {
    int ten=10;
    power(ten,exponent);

    return mantissa/double(ten);

    int temp=ten;
  if (mantissa<0)
  {
    mantissa*=-1;
  }
  while(temp/(mantissa%ten)>9)
  {
    cout << "0";
    temp=temp/10;
  }

    return mantissa%ten;
  }
  return mantissa;

}
