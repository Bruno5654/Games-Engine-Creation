\// Program17LocalVariablesAndCopies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int addTwo(int num);

int main()
{
    int myNum = 6;
    cout << "MAIN [before]: myNum = " << myNum << endl;

    addTwo(myNum);

    cout << "MAIN [after]: myNum = " << myNum << endl;
}

void addTwo(int num)
{
    num += 2;
    cout << "FUNCTION: num = " << num << endl;
}



