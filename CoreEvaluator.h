
#ifndef COREEVALUATOR_H
#define COREEVALUATOR_H

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tokenizer.h"
#include "TokenOfType.h"
#include "Token.h"

using namespace std;

class CoreEvaluator
{
public:
  CoreEvaluator();
  ~CoreEvaluator();
  vector<Token>* ShuntingOperations(vector<Token>* v);
  Token GetToken(int index);
  Token GetOperator();
  void AddToken(Token str);
  void DeleteToken(int index);
  string backToString(Token t);

private:
  queue<Token>* output;
  stack<Token>* operators;
  // vector<Token> unSorted (copy InitialVector, output from Tokenizer);
  vector<Token>* unSort;
  vector<Token>* Sorted;


};

#endif
