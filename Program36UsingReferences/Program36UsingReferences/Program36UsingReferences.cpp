#include <iostream>
using namespace std;

void minus25(int& num);
void plus25(int& num);

int main()
{
    int num = 0;
    int& rNum = num;
    cout << "Please enter a number.\n";
    cin >> num;
    cout << "Your number = " << num << "\n";
    plus25(rNum);
    cout << "Your number + 25 = " << num << "\n";
    cout << "Please enter another number.\n";
    cin >> num;
    minus25(rNum);
    cout << "Your number - 25 = " << num << "\n";
}

void minus25(int& num)
{
    num -= 25;
}

void plus25(int& num)
{
    num += 25;
}