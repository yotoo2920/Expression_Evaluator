#ifndef CALCULATE_H
#define CALCULATE_H


#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Number.h"
#include "Divide.h"
#include "Factorial.h"
#include  "Power.h"
#include "Token.h"
#include "vector"
#include <stack>

using namespace std;

class Calculate
{
    public:
    Calculate();
    long long resultMantissa;
    long long resultExp;
    void getCalcultation(vector<Token*>* sortedList);
    stack <Number*> calculationStack;
    void pushNuber(vector<Token*>* sortedList,int& i,stack <Number*>& calculationStack );
    void addTwoNumbers(vector<Token*>* sortedList,int& i,stack <Number*>& calculationStack);
    void subTwoNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void multTwoNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void divTwoNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void powNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void factNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
};

#endif // CALCULATE_H
