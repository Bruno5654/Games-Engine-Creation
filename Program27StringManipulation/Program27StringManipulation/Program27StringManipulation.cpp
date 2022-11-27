#include <iostream>
#include <string>
using namespace std;
int main()
{
    string userInput, userInput2;
    string testString = "Do you know who loves C++? XX does!";
    int userInputLength;
    cout << "Please enter your name.\n";
    cin >> userInput;
    userInputLength = size(userInput);

    testString.insert(28, userInput);
    cout << testString << "\n";

    testString.replace(27,userInputLength+2, userInput);
    cout << testString << "\n";

    cout << "Please enter a second, longer name.\n";
    cin >> userInput2;
    
    testString.replace(27, userInputLength, userInput2);
    cout << testString << "\n";

}

