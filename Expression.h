#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

using namespace std;

class Expression
{
  public:
    Expression();
    virtual ~Expression();
    // virtual methods
    virtual string backToString() = 0; // abstract method to get any result back to string
    virtual void Solve() = 0; // abstract method to evaluate all kind of expressions

  private:
};

#endif // EXPRESSION_H
