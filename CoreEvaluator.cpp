/*
  the imput of this class is vector with Token objects in unSorted order
  we will use shunting yard to get a Sorted vector in reverse polish notation
*/
#include <iostream>

#include "CoreEvaluator.h"

using namespace std;

CoreEvaluator::CoreEvaluator()
{
  toUnSort = NULL; // to a vector
  toSorted = NULL; // to a vector
  toQueue = NULL; // to a queue
  toStack = NULL; // to a stack
}

CoreEvaluator::~CoreEvaluator()
{

}

void CoreEvaluator::ShuntingOperations(vector<string>& v)
{
  // vector
  vector<string> unSort (v); // copying the vector being pass as a parameter
  toUnSort = &unSort;

  // queue
  queue<Token> output;
  toQueue = output;

  // stack
  stack<Token> operators;
  toStack = operators;

  // temp token
  Token* tempToken = NULL;

  // iterating token by token
  for (int i=0; i < unSort.size(); i++)
  {
    // 1 - reading at i
    tempToken = toUnSort->at(i);

    // 2 - int, real or negative values
    if (tempToken->GetTokenType() == IntValue || tempToken->GetTokenType() == RealValue || tempToken->GetTokenType() == NegValue)
    {
      toQueue->Push(tempToken);
    }

    // 3 - functions sin, cos, tan, log, e, root, factorial
    if (tempToken->GetTokenType() == sinFunc || tempToken->GetTokenType() == cosFunc || tempToken->GetTokenType() == tanFunc || tempToken->GetTokenType() == LogFunc || tempToken->GetTokenType() == E_Func || tempToken->GetTokenType() == RootFunc || tempToken->GetTokenType() == FactFunc)
    {
      toStack->Push(tempToken);
    }

    // 4 - argument separator e.g. openPar and closePar
    if ()
    {

    }

    // 5 - an operator +,-,*,/,power ^
    if (tempToken->GetTokenType() == PlusSign || tempToken->GetTokenType() == SubstSign || tempToken->GetTokenType() ==  MultSign || tempToken->GetTokenType() ==  DivSign || tempToken->GetTokenType() == PowerFunc)
    {
      // 5.1 - while operator on the top of the stack
      Token* tempOpt = toStack->Top();
      while (tempOpt->GetTokenType() != openPar || tempOpt->GetTokenType() != closePar || tempOpt->GetTokenType() != sinFunc || tempOpt->GetTokenType() != cosFunc || tempOpt->GetTokenType() != tanFunc || tempOpt->GetTokenType() != LogFunc || tempOpt->GetTokenType() != E_Func || tempOpt->GetTokenType() != RootFunc || tempOpt->GetTokenType() != FactFunc)
      {
        // 5.2
        if (tempToken->GetAssociativity() == Left && tempToken->GetPrecedence() <= tempOpt->GetPrecedence())
        {
          toQueue->Push(tempOpt->Pop()); // pop onto the queue
        }
        // 5.3
        if (tempToken->GetAssociativity() == Right && tempToken->GetPrecedence() < tempOpt->GetPrecedence())
        {
          toQueue->Push(tempOpt->Pop()); // pop onto the queue
        }
        tempOpt = toStack->Top(); // update top position in the stack
      }
    // 5.4
    toStack->Push(tempToken);
    }

    // 6 - openPar
    if (tempToken->GetTokenType() == openPar)
    {
      toStack->Push(tempToken);
    }

    // 7 - closePar
    if (tempToken->GetTokenType() == closePar)
    {
      // 7.1
      Token* tempOpt = toStack->Top();
      while (!tempOpt->GetTokenType() == openPar)
      {
        toQueue->Push(tempOpt->Pop()); // pop onto the queue
        tempOpt = toStack->Top(); // update top position in the stack
      }
      // 7.2
      toStack->Pop(tempOpt); // pop from the stack to nowhere

      // 7.3
      if (tempOpt = toStack->Top() == sinFunc || tempOpt->GetTokenType() == cosFunc || tempOpt->GetTokenType() == tanFunc || tempOpt->GetTokenType() == LogFunc || tempOpt->GetTokenType() == E_Func || tempOpt->GetTokenType() == RootFunc || tempOpt->GetTokenType() == FactFunc)
      {
        toQueue->Push(tempOpt->Pop()); // pop onto the queue
      }

      // 7.4
    }
  } // end of the for

  

}

string CoreEvaluator::backToString(string t)
{
return "s";
}
