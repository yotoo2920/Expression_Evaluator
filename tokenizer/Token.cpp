#include <string>
#include <vector>
#include <stdexcept>

#include "Token.h"


using namespace std;

Token::Token(TokenOfType type, string str)
{
  //
}

Token::~Token()
{
  //
}

// hierarchy of tokens, looking the precedence "will be use during the shunting yard"
int Token::GetPrecedence()
{
  if (typeOfToken == TokenOfType.ClosePar || typeOfToken == TokenOfType.OpenPar )
   return 5;
  if (typeOfToken == TokenOfType.PowerValue)
    return 4;
  if (typeOfToken == TokenOfType.MultSign || typeOfToken == TokenOfType.DivSign)
    return 3;
  if (typeOfToken == TokenOfType.PlusSign || typeOfToken == TokenOfType.SubstSign)
    return 2;
  // return value for the rest of the tokens
  return 1;
}


// only relevant for operators "will be use during the shunting yard"
AssociativityEnum Token::GetAssociativity()
{
  if (typeOfToken == TokenOfType.PowerValue) // power value ^
   return AssociativityEnum.Right;

   return AssociativityEnum.Left;  // add, sub, mult, div
}

TokenOfType Token::GetTokenType()
{

}
