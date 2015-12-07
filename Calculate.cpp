#include <string>
#include <vector>
#include <iostream>

#include "stdlib.h"
#include "Calculate.h"

using namespace std;

Number* n1 = new Number();
Number* n2 = new Number();

Add* add= new Add();
Number* sum=new Number;

Subtract* sub= new Subtract();
Number* dif= new Number();

Divide* divi= new Divide();
Number* division=new Number();

Multiply* mult= new Multiply();
Number* product= new Number();

Factorial* fac= new Factorial();
Number* factNum=new Number();

Power* pow= new Power();
Number* powNum= new Number();

Root* root= new Root();
Number* rootNum= new Number();

Sine* sine= new Sine();
Number* sineNum= new Number();

Cosine* cosine= new Cosine();
Number* cosineNum= new Number();

Tangent* tangent= new Tangent();
Number* tangentNum= new Number();

Secant* secant= new Secant();
Number* secantNum= new Number();

Cosecant* cosecant= new Cosecant();
Number* cosecantNum= new Number();

Cotangent* cotangent= new Cotangent();
Number* cotangentNum= new Number();

Ln* ln= new Ln();
Number* lnNum= new Number();

Log* log= new Log();
Number* logNum= new Number();

Calculate::Calculate()
{
    //ctor
	isValid = true;
}
void Calculate::getCalcultation(vector<Token*>* sortedList)
{
  for (int i=0; i < sortedList->size(); i++)
	{
    //cout << sortedList->at(i)->GetTokenStr();
		if (sortedList->at(i)->GetTokenType()==IntValue|| sortedList->at(i)->GetTokenType()==RealValue|| sortedList->at(i)->GetTokenType()==NegValue)
		{
		  pushNuber(sortedList,i,calculationStack);
		}

		// if + found call addition and the same for the rest of the operants
		if (sortedList->at(i)->GetTokenStr()=="+")
		{
		  addTwoNumbers(sortedList,i,calculationStack);
		}

		if (sortedList->at(i)->GetTokenStr()=="-")
		{
		  subTwoNumbers(sortedList,i,calculationStack);
		}

		if (sortedList->at(i)->GetTokenStr()=="*")
		{
		  multTwoNumbers(sortedList,i,calculationStack);
		}

		if (sortedList->at(i)->GetTokenStr()=="/")
		{
		  divTwoNumbers(sortedList,i,calculationStack);
		}

		if (sortedList->at(i)->GetTokenStr()=="^")
		{
		  powNumbers(sortedList,i,calculationStack);
		  if(!isValid) return; // checking for int exponet only
		}

		if (sortedList->at(i)->GetTokenStr()=="!")
		{
		  factNumbers(sortedList,i,calculationStack);
		}

    if (sortedList->at(i)->GetTokenStr()=="root")
		{
		  rootNumbers(sortedList,i,calculationStack);
		}

    if (sortedList->at(i)->GetTokenStr()=="sin")
		{
		  sineNumbers(sortedList,i,calculationStack);
		}

    if (sortedList->at(i)->GetTokenStr()=="cos")
		{
		  cosineNumbers(sortedList,i,calculationStack);
		}

    if (sortedList->at(i)->GetTokenStr()=="tan")
		{
		  tangentNumbers(sortedList,i,calculationStack);
		}

    if (sortedList->at(i)->GetTokenStr()=="sec")
		{
		  secNumbers(sortedList,i,calculationStack);
		}

    if (sortedList->at(i)->GetTokenStr()=="csc")
		{
		  cscNumbers(sortedList,i,calculationStack);
		}

    if (sortedList->at(i)->GetTokenStr()=="cot")
		{
		  cotNumbers(sortedList,i,calculationStack);
		}

    if (sortedList->at(i)->GetTokenStr()=="ln")
		{
		  lnNumbers(sortedList,i,calculationStack);
		}

    if (sortedList->at(i)->GetTokenStr()=="log")
		{
		  logNumbers(sortedList,i,calculationStack);
		}
	}
 calculationStack.top()->printNumber();
}

void Calculate::addTwoNumbers(vector<Token*>* sortedList,int& i,stack <Number*>& calculationStack){

  n1=calculationStack.top();
	calculationStack.pop();
	n2=calculationStack.top();
	calculationStack.pop();
	sum=add->getSum(n2,n1);
  calculationStack.push(sum);

}

void Calculate::subTwoNumbers(vector<Token*>* sortedList,int& i,stack <Number*>& calculationStack){

  n1=calculationStack.top();
	calculationStack.pop();
	n2=calculationStack.top();
	calculationStack.pop();
	dif=sub->getDifference(n2,n1);
  calculationStack.push(dif);
}

void Calculate::multTwoNumbers(vector<Token*>* sortedList,int& i,stack <Number*>& calculationStack){

  n1=calculationStack.top();
	calculationStack.pop();
	n2=calculationStack.top();
	calculationStack.pop();
	product=mult->getProduct(n2,n1);
  calculationStack.push(product);
}

void Calculate::divTwoNumbers(vector<Token*>* sortedList,int& i,stack <Number*>& calculationStack){

  n1=calculationStack.top();
	calculationStack.pop();
	n2=calculationStack.top();
	calculationStack.pop();
	division=divi->getDividend(n2,n1);
  calculationStack.push(division);
}

void Calculate::powNumbers(vector<Token*>* sortedList,int& i,stack <Number*>& calculationStack){

  n1=calculationStack.top();
	calculationStack.pop();
	n2=calculationStack.top();
	calculationStack.pop();
	if(n1->exponent > 0) {
		cout<<"Error, exponents may only be integer values"<<endl;
		isValid = false;
		return;
	}
	powNum=pow->getPower(n2,n1);
  calculationStack.push(powNum);
}

void Calculate::factNumbers(vector<Token*>* sortedList,int& i,stack <Number*>& calculationStack){

  n1=calculationStack.top();
	calculationStack.pop();
	factNum=fac->getFactorial(n1);
  calculationStack.push(factNum);

}

void Calculate::rootNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack)
{
  n1=calculationStack.top();
	calculationStack.pop();
	n2=calculationStack.top();
	calculationStack.pop();
	rootNum= root->getRoot(n2,n1);
  calculationStack.push(rootNum);
}

void Calculate::sineNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack)
{
  n1=calculationStack.top();
	calculationStack.pop();
	sineNum=sine->getSine(n1);
  calculationStack.push(sineNum);
}

void Calculate::cosineNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack)
{
  n1=calculationStack.top();
	calculationStack.pop();
	cosineNum=cosine->getCosine(n1);
  calculationStack.push(cosineNum);
}

void Calculate::tangentNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack)
{
  n1=calculationStack.top();
	calculationStack.pop();
	tangentNum=tangent->getTangent(n1);
  calculationStack.push(tangentNum);
}

void Calculate::secNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack)
{
  n1=calculationStack.top();
	calculationStack.pop();
	secantNum=secant->getSecant(n1);
  calculationStack.push(secantNum);
}

void Calculate::cscNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack)
{
  n1=calculationStack.top();
  calculationStack.pop();
  cosecantNum=cosecant->getCosecant(n1);
  calculationStack.push(cosecantNum);
}

void Calculate::cotNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack)
{
  n1=calculationStack.top();
  calculationStack.pop();
  cotangentNum=cotangent->getCotangent(n1);
  calculationStack.push(cotangentNum);
}

void Calculate::lnNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack)
{
  n1=calculationStack.top();
  calculationStack.pop();
  lnNum=ln->getLn(n1);
  calculationStack.push(lnNum);
}

void Calculate::logNumbers(vector<Token*>* sortedList,int& i,stack <Number*> &calculationStack)
{
      n1=calculationStack.top();
      calculationStack.pop();
      n2=calculationStack.top();
      calculationStack.pop();
      logNum= log->getLog(n2,n1);
      calculationStack.push(logNum);
}

void Calculate::pushNuber(vector<Token*>* sortedList, int& i,stack <Number*>& calculationStack){

  Number* n3 = new Number();
  if (sortedList->at(i)->GetTokenType()!=NegValue)
  {
    n3->converStringToNumber(sortedList->at(i)->GetTokenStr());
  }
  else
  {
    n3->converStringToNumber(sortedList->at(i)->GetTokenStr().substr(1,sortedList->at(i)->GetTokenStr().size()-1));
    n3->mantissa*=-1;
  }
	calculationStack.push(n3);
}
