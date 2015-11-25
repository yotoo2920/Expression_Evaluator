#ifndef TOKENOFTYPE_H
#define TOKENOFTYPE_H

enum TokenOfType
{
   IntValue, RealValue, NegValue // whole, decimal, a Negative type of value
   PlusSign, SubstSign, MultSign, DivSign, // +,-,*,/, operators
   LogValue, E_Value, PowerValue, RootValue, // Log, e^, x^n, (x)^(1/2) value
   PIvalue, // constants (add more)  maybe avogadro's # etc
   OpenPar, ClosePar, // open and close parenthesis
   Error // token with an error to be added to syntax_error vector
};

#endif
