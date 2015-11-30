/*
  the imput of this class is vector with Token objects in unSorted order
  we will use shunting yard to get a Sorted queue in reverse polish notation
*/

#include <iostream>
#include <stdexcept>

#include "CoreEvaluator.h"

using namespace std;

CoreEvaluator::CoreEvaluator()
{

}

CoreEvaluator::~CoreEvaluator()
{

}

queue<Token>* CoreEvaluator::ShuntingOperations(vector<Token>* toUnSort)
{
  if (toUnSort == NULL) throw new exception();

  // queue
  queue<Token>* toQueue = new queue<Token>();

  // stack
  stack<Token> operators;

  // temp token
  Token* tempToken = NULL;

  // iterating token by token
  for (int i=0; i < toUnSort.size(); i++)
  {
    // 1 - reading at i
    tempToken = toUnSort->at(i);

    // 2 - int, real or negative values
    if (isNumber(Token* tempToken))
    {
      toQueue->push(tempToken);
    }

    // 3 - functions sin, cos, tan, log, e, root, factorial
    else if (isFunction(Token* tempToken))
    {
      toStack->push(tempToken);
    }

    // 5 - an operator +,-,*,/,power ^
    else if (isOperator(tempToken))
    {
      // if the stack is not empty
      if (!toStack->empty())
      {
        // 5.1 - while operator on the top of the stack
        Token* tempOpt = toStack->top();
        while (tempOpt != NULL && ((tempToken->GetAssociativity() == Left && tempToken->GetPrecedence() <= tempOpt->GetPrecedence()) || (tempToken->GetAssociativity() == Right && tempToken->GetPrecedence() < tempOpt->GetPrecedence())))
        {
          // 5.2
          toQueue->push(toStack->pop()); // pop onto the queue
          tempOpt = toStack->top();
        }
      }
    // 5.4
    toStack->push(tempToken);
    }

    // 6 - openPar
    else if (tempToken->GetTokenType() == openPar)
    {
      toStack->push(tempToken);
    }

    // 7 - closePar
    else if (tempToken->GetTokenType() == closePar)
    {
      // 7.1
      Token* tempOpt = toStack->top();
      while (tempOpt != NULL && (!(tempOpt->GetTokenType() == openPar)))
      {
        toQueue->push(toStack->pop()); // pop onto the queue
        tempOpt = toStack->top(); // update top position in the stack
      }
      // 7.4
      if(toStack->empty())
      {
        throw new exception("Mismatched parentheses.");
      }
      // 7.2
      toStack->pop(tempOpt); // pop from the stack to nowhere
    }

  } // end of the for

  while(!toStack->empty())
  {
    if (toStack->top() == openPar || toStack->top() == closePar) // is parentheses
    {
      throw new exception("Mismatched parentheses.");
    }
    toQueue->push(toStack->pop()); // pop onto the queue
  }

  return toQueue;
}

// int, real, or negative values
bool CoreEvaluator::isNumber(Token* tempToken)
{
  return (tempToken->GetTokenType() == IntValue || tempToken->GetTokenType() == RealValue || tempToken->GetTokenType() == NegValue);
}

// is operators
bool CoreEvaluator::isOperator(Token* tempToken)
{
  return (tempToken->GetTokenType() == PlusSign || tempToken->GetTokenType() == SubstSign || tempToken->GetTokenType() ==  MultSign || tempToken->GetTokenType() ==  DivSign || tempToken->GetTokenType() == PowerFunc);
}

// is functions
bool CoreEvaluator::isFunction(Token* tempToken)
{
  return (tempToken->GetTokenType() == sinFunc || tempToken->GetTokenType() == cosFunc || tempToken->GetTokenType() == tanFunc || tempToken->GetTokenType() == LogFunc || tempToken->GetTokenType() == E_Func || tempToken->GetTokenType() == RootFunc || tempToken->GetTokenType() == FactFunc);
}
