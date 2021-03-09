#include <iostream>

using namespace std;

int main()
{
    int firstNumber = 0, secondNumber = 0, mult = 0;

    cout << "Write first number: ";
    cin >> firstNumber;
    cout << "Write second number: ";
    cin >> secondNumber;

    mult = firstNumber * secondNumber;

    while (firstNumber != secondNumber)
    {
        if (firstNumber > secondNumber)
        {
            firstNumber = firstNumber - secondNumber;
        }
        else
        {
            secondNumber = secondNumber - firstNumber;
        }
    }

    cout << "Least common multiple: " << mult / firstNumber << endl;
}