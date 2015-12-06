#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "UserInterface.h"

using namespace std;

int main(int argc, char const *argv[])
{
	
	UserInterface* user = new UserInterface();
	bool in = true;

	cout << endl;
	cout<< "Welcome to Calculator" << endl;
   
	while(in)
	{
		cout << endl;
		cout << "C = Calculate 'OR' H = Help   'OR'   O = Off" << endl;
		cout << "--------------------------------------------" << endl;
		cout << endl;

		string choice;
		cin >> choice;

		if (choice == "C")
		{
			// if you reached this point then user input is a math expression
			cin.clear();
			cin.ignore(256,'\n');
			user->Test();
		}
		else if (choice == "c")
		{   
			// if you reached this point then user input is a math expression
			cin.clear();
			cin.ignore(256,'\n');
			user->Test();
		}
		else if (choice == "h")
		{
			user->Menu();
			cin.clear();
		}
		else if (choice == "H")
		{
			user->Menu();
			cin.clear();
		}
		else if (choice == "o")
		{
			in = false;
			cout << "Goodbye!" << endl;
			cout << endl;
		}
		else if (choice == "O")
		{
			in = false;
			cout << "Goodbye!" << endl;
			cout << endl;

		}
		else 
		{
			cout << "Wrong choice, try again please.";
			cin.clear();
		}
	}
	return 0;
}
