// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    bool a = false;
    bool b = true;

    int num1 = 12;
    int num2 = 5;
    int num3 = 7;

    if (a)
    {
        num1 += 10;
        num2 += 15;
    }

    if (b)
    {
        num1 ++;
        num3 += 20;
    }

    if (a == false && b == false)
    {
        num1 --;
        num2 --;
        num3 --;

    }

    std::cout << num1 << "\n" << num2 << "\n" << num3 << std::endl;
}


