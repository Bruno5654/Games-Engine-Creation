#include <iostream>
using namespace std;
bool OddOrEven(int a);
void OutputResults(int numOfOdd, int oddTotal, int numOfEven, int evenTotal);

int main()
{
    int numOfOdd = 0, oddTotal = 0, numOfEven = 0, evenTotal = 0, playerInput = 0;
 
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter a number: " << endl;
        cin >> playerInput;
        cout << endl;

        bool isEven = OddOrEven(playerInput);

        if (isEven)
        {
            evenTotal += playerInput;
            numOfEven++;
        }
        else
        {
            oddTotal += playerInput;
            numOfOdd++;
        }
       
    }

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    OutputResults(numOfOdd, oddTotal, numOfEven, evenTotal);
}

bool OddOrEven(int a)
{
    bool result = false;

    if (a % 2 == 0)
        result = true;
    else
        result = false;
   
    return(result);
}

void OutputResults(int numOfOdd, int oddTotal, int numOfEven, int evenTotal)
{
    cout << "You entered " << numOfEven << " even numbers and their sum is " << evenTotal << endl;
    cout << "You entered " << numOfOdd << " odd numbers and their sum is " << oddTotal << endl;
}
