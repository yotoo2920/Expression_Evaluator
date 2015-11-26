/*
  the imput of this class is vector with Token objects in unSorted order
  we will use shunting yard to get a Sorted vector in reverse polish notation
*/

#include "CoreEvaluator.h"

using namespace std;

CoreEvaluator::CoreEvaluator()
{
  //
}

CoreEvaluator::~CoreEvaluator()
{
  //
}

void CoreEvaluator::ShuntingOperations(vector<Token>& v)
{

  vector<Token> unSort = v;

}

Token CoreEvaluator::GetToken(int index)
{

}

Token CoreEvaluator::GetOperator()
{


}

void CoreEvaluator::AddToken(Token t)
{
  // if type operator then to the stack


  // if type !operator then to the queue

}

void CoreEvaluator::DeleteToken(int index)
{

}

string CoreEvaluator::backToString(Token t)
{

}
