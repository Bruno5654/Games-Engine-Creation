#include <iostream>
using namespace std;

int main()
{
    int inputArray[10], userInput = 0, smallestPosition = 0;

    for (int i = 0; i < 10; i++)
    {
        cout << "Please enter an integer:\n";
        cin >> userInput;
        inputArray[i] = userInput;

    }

    for (int i = 1; i < 10; i++)
    {
        if (inputArray[i] < inputArray[smallestPosition])
        {
            smallestPosition = i;
        }

    }

    cout << "The smallest value is " << inputArray[smallestPosition] << " and it is stored in position " << smallestPosition+1 << ".\n";
    
    return 0;
}

