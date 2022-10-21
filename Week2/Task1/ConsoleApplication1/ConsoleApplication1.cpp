// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
   
    bool a = true;
    int num = 0;
    int num2 = 0;
    int num3 = 0;

    if (a)
    {
        num++;
    }
    num2 += 5;
    num3 *= 2;

    if (a)
    {
        num++;
        num2 += 5;
    }
    num3 *= 2;

    std::cout << num << "\n" << num2 << "\n" << num3 << std::endl;
}
