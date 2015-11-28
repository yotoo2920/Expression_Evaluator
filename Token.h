#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>

#include "TokenOfType.h"
#include "Associativity.h"
#include "TokenOfType.h"

using namespace std;

class Token
{

public:
  Token(TokenOfType type, string str);
  ~Token();
  int GetPrecedence();
  AssociativityEnum GetAssociativity();
  TokenOfType GetTokenType();
  string GetTokenStr();

private:
  TokenOfType typeOfToken;
  string valueStr;

};

#endif
