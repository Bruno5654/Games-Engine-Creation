// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    using namespace std;
    int num1, num2;
    int PlayerInput;
    char PlayAgain;
    

    cout << "Play again?\nEnter y or n.." << endl;
    cin >> PlayAgain;
    
    switch (PlayAgain)
    {
        case 'y':
            cout << "You chose play again." << endl;
        break;

        case 'n':
            cout << "Goodbye." << endl;
        break;

        default:
            cout << "Thats not y or n." << endl;
        break;

    }
   
}


