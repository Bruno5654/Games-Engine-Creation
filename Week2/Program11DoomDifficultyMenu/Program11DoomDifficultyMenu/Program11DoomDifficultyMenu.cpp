// Program11DoomDifficultyMenu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int PlayerInput;

	cout << "Please choose your difficulty:\n1. I'm too young to die.\n2. Hey, not to rough!\n3. Hurt me plenty.\n4. Ultra-Violence.\n5. Nightmare..." << endl;
	cin >> PlayerInput;

	switch (PlayerInput)
	{
		case 1:
			cout << "Games journalist huh." << endl;
		break;
		
		case 2:
			cout << "Should be a breeze right." << endl;
		break;

		case 3:
			cout << "Be prepared for a fight." << endl;
		break;

		case 4:
			cout << "Rip and tear until it is done." << endl;
		break;

		case 5:
			cout << "Brave... or foolish. Time will tell." << endl;
		break;

		default:
			cout << "Not a valid choice. Please enter a number." << endl;
		break;
	}
}

