#ifndef COREEVALUATOR_H
#define COREEVALUATOR_H

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tokenizer.h"
#include "Token.h"

using namespace std;

class CoreEvaluator: public Expression
{
public:
  CoreEvaluator();
  ~CoreEvaluator();
  void TokenOperations(vector<Token>& v);
  Token GetToken(int index);
  Token GetOperator();
  void AddToken(Token t);
  void DeleteToken(int index);
  string backToString();

protected:
  queue<Token, vector<Token> >* output;
  stack<Token, vector<Token> >* operators;
  // vector<Token> unSorted (copy InitialVector, output from module 1);
  vector<Token>* unSorted;
  vector<Token>* Sorted;


};

#endif
