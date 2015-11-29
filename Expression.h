#ifndef EXPRESSION_H
#define EXPRESSION_H
<<<<<<< HEAD
#include<string>
using namespace std;
class Expression
{
    public:
    string type;
        //Expression();
        //virtual ~Expression();
    protected:
    private:
=======

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
>>>>>>> 524d1514a7d3c7af05cb76e6803e458a22d511ec
};

#endif // EXPRESSION_H
