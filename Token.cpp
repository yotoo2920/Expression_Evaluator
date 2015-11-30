#include <string>
#include <vector>
#include <stdexcept>

#include "Token.h"


using namespace std;

Token::Token()
{
  valueStr = " ";
  typeOfToken = None;
}

Token::Token(TokenOfType type, string str)
{
  this->valueStr = str;
  this->typeOfToken = type;
}

Token::~Token()
{

}

// hierarchy of tokens, looking the precedence "will be use during the shunting yard"
int Token::GetPrecedence()
{
  if (typeOfToken == ClosePar || typeOfToken == OpenPar )
   return 5;
  if (typeOfToken == PowerFunc)
    return 4;
  if (typeOfToken == MultSign || typeOfToken == DivSign)
    return 3;
  if (typeOfToken == PlusSign || typeOfToken == SubstSign)
    return 2;
  // return value for the rest of the tokens
  return 1;
}


// only relevant for operators "will be use during the shunting yard"
AssociativityEnum Token::GetAssociativity()
{
  if (typeOfToken == PowerFunc) // power value ^
   return Right;

   return Left;  // add, sub, mult, div
}

TokenOfType Token::GetTokenType()
{
	return this->typeOfToken;
}

string Token::GetTokenStr() {
	return this->valueStr;
}
