#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>

#include "TokenOfType.h"

using namespace std;

class Token
{

public:
  Token(TokenOfType type, string str);
  ~Token();
  vector<Token> GetInitialVector();
  TokenOfType GetTokenType();
  string GetTokenStr();


protected:
  TokenOfType typeOfToken;
  string valueStr;
  vector<Token> initialVector;
}

#endif
