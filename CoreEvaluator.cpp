/*
 the imput of this class is vector with Token objects in unSorted order
 we will use shunting yard to get a Sorted queue in reverse polish notation
 */

#include <iostream>
#include <stdexcept>

#include "CoreEvaluator.h"

using namespace std;

CoreEvaluator::CoreEvaluator()
{
	isValid = true;
}

CoreEvaluator::~CoreEvaluator()
{

}

vector<Token*>* CoreEvaluator::ShuntingOperations(vector<Token>* toUnSort)
{
    if (toUnSort == NULL) throw new exception();

    // vector
    vector<Token*>* SortedVector = new vector<Token*>();

    // queue
    queue<Token*>* toQueue = new queue<Token*>();

    // stack
    stack<Token*>* toStack = new stack<Token*>();

    // temp token
    Token* tempToken;

    // iterating token by token
    for (int i=0; i < toUnSort->size(); i++)
    {
        // 1 - reading at i
        tempToken = &toUnSort->at(i);

        // 2 - int, real or negative values
        if (isNumber(tempToken))
        {
            toQueue->push(tempToken);
        }

        // 4 - for log(v,b) and coma ERROR checking
        else if (tempToken->GetTokenType() ==  Comma) // exa: 3,4
        {


            if (toStack->empty())
            {
                cout << "Invalid expression entered." << endl;
				isValid = false;
                while (!toQueue->empty())
                {
                    toQueue->pop(); // cleaning the queue before printing the error
                }
                break;
            }

            Token* tempOpt = toStack->top();

            if (tempOpt->GetTokenType() == OpenPar) // exa: sin(3,4)
            {
                toStack->pop(); // getting the OpenPar out

                if (!toStack->empty())
                {
                    tempOpt = toStack->top(); // update top position
                }
                else
                {
                    cout << "Invalid expression entered." << endl;
					isValid = false;
                    while (!toQueue->empty())
                    {
                        toQueue->pop(); // cleaning the queue before printing the error
                    }
                    break;
                }

                if (tempOpt->GetTokenType() == sinFunc || tempOpt->GetTokenType() == cosFunc || tempOpt->GetTokenType() == tanFunc || tempOpt->GetTokenType() == PowerFunc || tempOpt->GetTokenType() == FactFunc)
                {
                    cout << "Invalid expression entered." << endl;
					isValid = false;
                    while (!toQueue->empty())
                    {
                        toQueue->pop(); // cleaning the queue before printing the error
                    }
                    while (!toStack->empty())
                    {
                        toStack->pop(); // cleaning the queue before printing the error
                    }
                    break;
                }
                else // it is log
                {
                    Token* parth = new Token(OpenPar,"(");
                    toStack->push(parth); // adding the OpenPar back to stack
                    // adding and erassing the Comma
                    toStack->push(tempToken);
                    toStack->pop();
                }
            }
            else
            {
                // adding and erassing the Comma
                toStack->push(tempToken);
                toStack->pop();
            }
        }

        // 5 - an operator +,-,*,/,power ^, sin, cos, tan, factorial, log, root
        else if (isOperator(tempToken))
        {
            // if the stack is not empty
            if (!toStack->empty())
            {
                // 5.1 - while operator on the top of the stack
                Token* tempOpt = toStack->top();

                while (!toStack->empty() && isOperator(tempOpt) && ((tempToken->GetAssociativity() == Left && tempToken->GetPrecedence() <= tempOpt->GetPrecedence()) || (tempToken->GetAssociativity() == Right && tempToken->GetPrecedence() < tempOpt->GetPrecedence())))
                {
                    // 5.2
                    toQueue->push(toStack->top());
                    toStack->pop();
                    if (!toStack->empty())
                    {
                        tempOpt = toStack->top(); // update top position
                    }
                    else
                    {
                        break;
                    }
                }
            }
            // 5.4
            toStack->push(tempToken);
        }

        // 6 - openPar
        else if (tempToken->GetTokenType() == OpenPar)
        {
            toStack->push(tempToken);
        }

        // 7 - closePar
        else if (tempToken->GetTokenType() == ClosePar)
        {
            // 7.1
            Token* tempOpt = toStack->top();
            while (!toStack->empty() && tempOpt->GetTokenType() != OpenPar)
            {
                toQueue->push(toStack->top()); // pop onto the queue
                toStack->pop();
                tempOpt = toStack->top(); // update top position in the stack
            }
            // 7.4
            if(toStack->empty())
            {
                throw new logic_error("Mismatched parentheses.");
            }
            // 7.2
            toStack->pop(); // pop from the stack to nowhere
        }
        else
        {
            string str = tempToken->GetTokenStr();

            // clean memory

            //trow exception
            throw runtime_error( str + " is not a valid argument");
        }

    } // end of the for

    while(!toStack->empty())
    {
        if (toStack->top()->GetTokenType() == OpenPar || toStack->top()->GetTokenType() == ClosePar) // is parentheses
        {
            throw new logic_error("Mismatched parentheses.");
        }
        toQueue->push(toStack->top()); // pop onto the queue
        toStack->pop();
    }

    // passing token by token from the queue to the Sorted vector
    while (!toQueue->empty())
    {
        SortedVector->push_back(toQueue->front());
        toQueue->pop();
    }

    return SortedVector;
}

// int, real, or negative values
bool CoreEvaluator::isNumber(Token* tempToken)
{
    return (tempToken->GetTokenType() == IntValue || tempToken->GetTokenType() == RealValue || tempToken->GetTokenType() == NegValue);
}

// is operators
bool CoreEvaluator::isOperator(Token* tempToken)
{
    return (tempToken->GetTokenType() == PlusSign || tempToken->GetTokenType() == SubstSign || tempToken->GetTokenType() ==  MultSign || tempToken->GetTokenType() ==  DivSign || tempToken->GetTokenType() == PowerFunc || tempToken->GetTokenType() == sinFunc || tempToken->GetTokenType() == cosFunc || tempToken->GetTokenType() == tanFunc || tempToken->GetTokenType() == LogFunc || tempToken->GetTokenType() == RootFunc || tempToken->GetTokenType() == FactFunc);
}
