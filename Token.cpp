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
  if (typeOfToken == ClosePar || typeOfToken == OpenPar)
   return 5;
  if (typeOfToken == sinFunc || typeOfToken == cosFunc || typeOfToken ==  tanFunc || typeOfToken ==  LogFunc || typeOfToken == PowerFunc || typeOfToken ==  RootFunc || typeOfToken == FactFunc)
    return 4;
  if (typeOfToken == MultSign || typeOfToken == DivSign)
    return 3;
  if (typeOfToken == PlusSign || typeOfToken == SubstSign)
    return 2;
  if (typeOfToken == IntValue || typeOfToken == RealValue || typeOfToken == NegValue || typeOfToken == PIvalue || typeOfToken == Evalue)
    return 1;

  // from here all are error or don't matter
  return 0;
}


// only relevant for operators "will be use during the shunting yard"
AssociativityEnum Token::GetAssociativity()
{
  if (typeOfToken == PowerFunc) // power value ^
  {
    return Right;
  }
  else
  {
    return Left;  // add, sub, mult, div
  }
}

TokenOfType Token::GetTokenType()
{
	return this->typeOfToken;
}

string Token::GetTokenStr() {
	return this->valueStr;
}
