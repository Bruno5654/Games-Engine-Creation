// Program15StarryOutput.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    int PlayerInput= 0;
    char ContinueLoop = 'Y';

    do
    {
        cout << "Please enter a number between 1 & 10:" << endl;
        cin >> PlayerInput;

        for (int i = 0; i <= PlayerInput; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }

        cout << "Have another go? (Y/N):" << endl;
        cin >> ContinueLoop;
    
    } while (tolower(ContinueLoop) == 'y');

    cout << "Goodbye." << endl;
    Sleep(1000);
   
}


