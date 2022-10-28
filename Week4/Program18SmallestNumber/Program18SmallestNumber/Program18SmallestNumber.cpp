#include <iostream>
using namespace std;

void SmallestNumber(int a, int b);
int Multiply(int a);
void Divide(float a);

int main()
{
	int playerInput1 = 0, playerInput2 = 0;

	for (int i = 0; i <= 2; i++)
	{
		cout << "Enter your first number:" << endl;
		cin >> playerInput1;
		
		cout << "Enter your second number:" << endl;
		cin >> playerInput2;
		
		SmallestNumber(playerInput1, playerInput2);
		cout << endl;

	}

	cout << endl;

	for (int j = 0; j <= 2; j++)
	{
		cout << "Enter your number to be multiplied:" << endl;
		cin >> playerInput1;

		int finalNumber = Multiply(playerInput1);
		Divide(finalNumber);

	}
	
}

void SmallestNumber(int a, int b)
{
		
	if (a < b)
	{
		cout << a << " is your smallest number." << endl;
	}	
	else if (b < a)
	{
		cout << b << " is your smallest number." << endl;
	}
	else
	{
		cout << a << " and " << b << " are the same number."  << endl;
	}

}

int Multiply(int a)
{
	return(a * 10);
}


void Divide(float a)
{
	int beforeDivide = a;
	a = a / 3;
	cout << beforeDivide << " divided by 3 = " << a << endl;
	cout << endl;
}