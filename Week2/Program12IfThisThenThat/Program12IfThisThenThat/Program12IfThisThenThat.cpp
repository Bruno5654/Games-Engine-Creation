// Program12IfThisThenThat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int Rain = 1, Snow = 2;
    int PlayerChoice1, PlayerChoice2;

    cout << "Please tell me if its raining with '1' or snowing with '2'." << endl;
    cin >> PlayerChoice1;
    cout << "What is the temperature in celsius?" << endl;
    cin >> PlayerChoice2;

    if (PlayerChoice1 == 1)
    {
        if (PlayerChoice2 > 15)
        {
            cout << "You should wear a light raincoat." << endl;
        }
        else
        {
            cout << "You should wear a thick coat." << endl;
        }
    }
    else if (PlayerChoice1 == 2)
    {
        if (PlayerChoice2 > 5)
        {
            cout << "You should wear somthing warm." << endl;
        }
        else if (PlayerChoice2 > 0)
        {
            cout << "You should wrap up well." << endl;
        }
        else
        {
            cout << "You should stay home." << endl;
        }
    }
    else
    {
        cout << "Havea nice day as it is neither raining nor snowing." << endl;
    }

    return 0;
}


