#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userInput;
    cout << "Please enter a sentence.\n";
    getline(cin, userInput);
    cout << "\n";
    cout << userInput << "\n";
    for (int i = 0; i < size(userInput); i++)
    {
        if (userInput[i] == 'e')
            userInput[i] = 'x';
    }
    cout << "\n";
    cout << userInput << "\n";
}

