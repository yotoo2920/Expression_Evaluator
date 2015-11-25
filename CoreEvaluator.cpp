/*
  the imput of this class is vector with Token objects in unSorted order
  we will use shunting yard to get a Sorted vector in reverse polish notation
*/

#include "CoreEvaluator.h"
#include "TokenOfType.h"

using namespace std;

CoreEvaluator::CoreEvaluator()
{
  //
}

CoreEvaluator::~CoreEvaluator()
{
  //
}

void CoreEvaluator::TokenOperations(vector<Token>& v)
{
  Token* newToken;

  for (int i=0; i < v.size(); i++)
  {
    newToken = v[i];
  }
}

Token CoreEvaluator::GetToken(int index)
{

}

Token CoreEvaluator::GetOperator()
{
  // pop operator from the stack
  return operators->Pop();

}

void CoreEvaluator::AddToken(Token t)
{
  // if type operator then to the stack
  

  // if type !operator then to the queue

}

void CoreEvaluator::DeleteToken(int index)
{

}

string CoreEvaluator::backToString()
{

}
