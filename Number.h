#ifndef NUMBER_H
#define NUMBER_H


using namespace std;

class Number
{
  public:
    Number();
    //Number(string &strTo);
    Number(int ,int);
    int mantissa;
    int exponent ;
  string strToNum;
    void converStringToNumber(string str);
    void power(int&, int&);
    void printNumber();
    void reduceNumber();

};

#endif // NUMBER_H
