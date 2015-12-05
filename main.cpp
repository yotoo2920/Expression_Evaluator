#include <string>
#include <vector>
#include <iostream>

#include "UserInterface.h"

using namespace std;

int main(int argc, char const *argv[])
{
	UserInterface* user = new UserInterface();
	cout << endl;
	cout<< "Welcome to Calculator" << endl;
	cout << endl;
	cout << "H = Help   OR" << "   O = Off" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
	char choice;
	while(choice != 'o'){
		user->Test();

		cin >> choice;

		switch(choice){
			case 'h':
				user->Menu();
				break;

			case 'H':
				user->Menu();
				break;

			case 'r':
				break;

			case 'o':
				cout << "Goodbye!" << endl;
				break;

			case 'O':
				cout << "Goodbye!" << endl;
				break;
		}
	}
	return 0;
}
