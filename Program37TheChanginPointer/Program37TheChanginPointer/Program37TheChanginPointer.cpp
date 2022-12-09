#include <iostream>
using namespace std;

void inputDetails(int* n1, int* n2);
void outputDetails(int& n1, int& n2, int* pnum);

int main()
{
	int num1 = 0;
	int num2 = 0;

	inputDetails(&num1,&num2);

	int* pNum = &num1;
	cout << "\n";
	cout << "pNum = num 1.\n";
	outputDetails(num1,num2,pNum);
	pNum = &num2;
	cout << "\n";
	cout << "pNum = num 2.\n";
	outputDetails(num1, num2, pNum);
}

void inputDetails(int* n1, int* n2)
{
	cout << "Input your first number.\n";
	cin >> *n1;
	cout << "Input your second number.\n";
	cin >> *n2;
	
}

void outputDetails(int& n1, int& n2, int* pnum)
{
	cout << "num1 value = " << n1 << "\n";
	cout << "num1 address = " << &n1 << "\n";;
	cout << "num2 value = " << n2 << "\n";;
	cout << "num2 address = " << &n2 << "\n";;
	cout << "pNum value = " << pnum << "\n";;
	cout << "pNum dereferenced value = " << *pnum << "\n";;
	cout << "pNum address = " << &pnum << "\n";;

}

