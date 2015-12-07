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
#include "Root.h"
#include "Sine.h"
#include "Cosine.h"
#include "Tangent.h"
#include "Secant.h"
#include "Cosecant.h"
#include "Cotangent.h"
#include "Ln.h"
#include "Log.h"


#include <stack>

using namespace std;

class Calculate
{
    public:
    Calculate();
	bool isValid;
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
    void rootNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void sineNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void cosineNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void tangentNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void secNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void cscNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void cotNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void lnNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
    void logNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack);
};

#endif // CALCULATE_H
