#ifndef LOG_H
#define LOG_H
#include "Add.h"
#include "Multiply.h"
#include "Power.h"
#include "Divide.h"
#include "Number.h"
#include "Ln.h"
#include "Subtract.h"

using namespace std;

class Log
{
private:
	Divide* div;
	Ln* nlog;
	Number* temp1;
	Number* temp2;
	Number* answer;

public:
	Log();
	Number* getLog(Number* value, Number* base);
};

#endif // LOG_H
