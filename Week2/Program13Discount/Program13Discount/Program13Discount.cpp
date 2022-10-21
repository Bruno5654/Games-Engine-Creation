// Program13Discount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    char UserStatus = 's';
    int GameChoice = 1;

    cout << "Please tell me your status with 's' for student, 't' for teacher or 'o' for other." << endl;
    cin >> UserStatus;

    tolower(UserStatus);

    cout << "Which game would you like? (1 or 2)" << endl;
    cin >> GameChoice;

    if(UserStatus == 's' || UserStatus == 't')
    {
        
        if (GameChoice == 1)
        {
            cout << "You will recive a 20% discount." << endl;
        }
        else
        {
            cout << "You will recive a 10% discount." << endl;
        }
    
    }
    else
    {
        cout << "You will not recive a discount." << endl;
    }

}


