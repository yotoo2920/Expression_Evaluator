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
    virtual string backToString() = 0;

    string type;
        //Expression();
        //virtual ~Expression();
    protected:
    private:
};

#endif // EXPRESSION_H
