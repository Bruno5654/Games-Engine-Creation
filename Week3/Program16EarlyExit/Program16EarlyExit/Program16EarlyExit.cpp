// Program16EarlyExit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int PlayerLife = 100, i = 1, PlayerInput = 0;
    bool EndedEarly = false, ContinueGame = true;

    do
    {
        cout << "Player Life = " << PlayerLife << endl;
        cout <<"Question " << i << ". How much damage shall I deal? " << endl;
        cin >> PlayerInput;

        PlayerLife -= PlayerInput;
        i++;

        if (i > 10 || PlayerLife <= 0)
            ContinueGame = false;

    } while (ContinueGame);

    if (i < 10 && PlayerLife <= 0)
        EndedEarly = true;

    if (EndedEarly)
    {
        cout << "Early end. Player died!" << endl;
    }
    else
    {
        cout << "All questions asked. Player survived!" << endl;
    }
}


