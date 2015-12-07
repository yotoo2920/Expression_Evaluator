#include <iostream>
#include "Divide.h"
#include "Number.h"
#include "Ln.h"
#include "Log.h"

using namespace std;

Log::Log()
{
	//empty constructor
}

Number* Log::getLog(Number* value, Number* base)
{
	div = new Divide();
	nlog = new Ln();
	temp1 = new Number();
	temp2 = new Number();
	answer = new Number();

	temp1 = nlog->getLn(value);
	temp2 = nlog->getLn(base);	
	answer = div->getDividend(temp1, temp2);

	return answer;
}
