
#ifndef COREEVALUATOR_H
#define COREEVALUATOR_H

#include <vector>
#include <string>
#include <stack>
#include <queue>

//#include "Tokenizer.h"
//#include "TokenOfType.h"
//#include "Token.h"

using namespace std;

class CoreEvaluator
{
  private:
    queue<Token>* toQueue;
    stack<Token>* toStack;
    // vector<Token> unSorted (copy InitialVector, output from Tokenizer);
    vector<Token>* toUnSort;
    vector<Token>* toSorted;

  public:
    CoreEvaluator();
    ~CoreEvaluator();
    // testing
    //void ShuntingOperations(vector<Token>& v);
    vector<Token>* ShuntingOperations(vector<Token>* v);
    Token GetToken(int index);
    Token GetOperator();
    void AddToken(Token t);
    void DeleteToken(int index);
    string backToString(Token t);
};

#endif
