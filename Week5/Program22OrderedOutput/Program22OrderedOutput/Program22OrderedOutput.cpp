#include <iostream>
#include <algorithm>
using namespace std;

int returnLargest(int array[]);

int main()
{
    int array[5], userInput = 0, largestValue = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "Please enter an integer:\n";
        cin >> userInput;
        array[i] = userInput;
    }

    sort(array, array+5);
    largestValue = returnLargest(array);

    cout << "\n";
    cout << "Array in accending order =\n";

    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << "\n";
    }
    
    cout << "\n";
    cout << "Array in descending order =\n";

    for (int i = 4; i >= 0; i--)
    {
        cout << array[i] << "\n";
    }
    
    cout << "\n";
    cout << "Largest value is " << largestValue << " and is stored in position 5.\n";



    return 0;
}

int returnLargest(int array[])
{
    int largestValue = array[4];

    return largestValue;
}