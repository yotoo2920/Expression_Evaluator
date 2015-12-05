#include <string>
#include <vector>

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

Calculate::Calculate()
{
    //ctor
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
		}

		if (sortedList->at(i)->GetTokenStr()=="!")
		{
		  factNumbers(sortedList,i,calculationStack);
		}
	}
 calculationStack.top()->printNumber();
 //cout << endl;
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
	powNum=pow->getPower(n2,n1);
  calculationStack.push(powNum);
}

void Calculate::factNumbers(vector<Token*>* sortedList,int& i,stack <Number*>& calculationStack){

  n1=calculationStack.top();
	calculationStack.pop();
	factNum=fac->getFactorial(n1);
  calculationStack.push(factNum);

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
