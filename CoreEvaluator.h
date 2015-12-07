
#ifndef COREEVALUATOR_H
#define COREEVALUATOR_H

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Token.h"

using namespace std;

class CoreEvaluator
{
  private:
    bool isOperator(Token* tempToken);
    bool isFunction(Token* tempToken);
    bool isNumber(Token* tempToken);

  public:
    CoreEvaluator();
    ~CoreEvaluator();
    vector<Token*>* ShuntingOperations(vector<Token>* toUnSort);
	bool isValid;
};

#endif
