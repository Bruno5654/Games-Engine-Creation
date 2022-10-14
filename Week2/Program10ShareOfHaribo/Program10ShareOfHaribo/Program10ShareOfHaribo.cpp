// Program10ShareOfHaribo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int HariboPackets = 40;
	int Students = 14;

	int StudentHaribo = HariboPackets / Students;
	int MyHaribo = HariboPackets % Students;
	
	cout << "The students recive " << StudentHaribo << " haribo packets." << endl;
	cout << "You recive " << MyHaribo << " haribo packets." << endl;

	return 0;
}

