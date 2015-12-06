#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include <vector>

#include "Tokenizer.hpp"
#include "CoreEvaluator.h"

using namespace std;

class UserInterface
{
	public:
		UserInterface();
		void Welcome();
		void Menu();
		void Test();
};

#endif
