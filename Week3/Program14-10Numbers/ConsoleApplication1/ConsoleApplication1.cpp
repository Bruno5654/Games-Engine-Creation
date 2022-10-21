// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int PlayerInput = 0, Sum = 0, i = 0;
	
	cout << "Please enter your first number:" << endl;
	cin >> PlayerInput;

	Sum += PlayerInput;
	i++;
	
	cout << "Enter another number:" << endl;
	cin >> PlayerInput;

	Sum += PlayerInput;
	i++;

	do
	{
		cout << "Add another number? Type 0 to end:" << endl;
		cin >> PlayerInput;

		Sum += PlayerInput;
		i++;

	} while (PlayerInput != 0);

	cout << "The sum of your numbers is " << Sum << " and their mean is " << (float)Sum / i << endl;

}

