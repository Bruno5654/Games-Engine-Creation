#include <iostream>

using namespace std;

int main()
{
    char userInput[50];
    char userFirstInit;
    char userMiddleInit;
    char userLastName[50];
    int stage = 0, j = 0;
    cout << "Please enter your first name inital, followed by your middle name inital and then full surname, each seperated by spaces.\n";
    cin.getline(userInput, 50);

    for (int i = 0; i < 50; i++)
    {
        if (userInput[i] == ' ')
        {
            if (stage == 0)
            {
                userFirstInit = userInput[i - 1];
                stage++;
            }
            else if (stage == 1)
            {
                userMiddleInit = userInput[i - 1];
                stage++;
            }
            
        }
        else if (stage == 2)
        {
            userLastName[j] = userInput[i];
            j++;
        }
    }

    cout << userFirstInit << "\n";
    cout << userMiddleInit << "\n";
    cout << userLastName << "\n";

}

