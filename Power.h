#ifndef POWER_H
#define POWER_H
#include "Number.h"

using namespace std;
class Power

{
	private:
		long long magnitude;
		int decimal;
		 int temp;
	public:
		Power();
		Number* getPower(Number* leftValue, Number* pow);
};
#endif // POWER_H
