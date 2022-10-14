// Program9ShareOfSavings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int MySavings = 2000;
    int YourPercentage = 50;
    int YourShare = (YourPercentage * (MySavings / 100));

    cout << "Your share: " << YourShare << endl;

    return 0;
}


