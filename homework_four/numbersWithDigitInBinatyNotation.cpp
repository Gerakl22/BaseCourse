#include <iostream>
#include <cmath>

using namespace std;

void numbersWithDigitInBinaryNotation(int number)
{
    int decimalNumbers = 0;

    for (int i = 1; i < number; i++)
    {
        while (number >= decimalNumbers)
        {
            cout << decimalNumbers << " ";
            decimalNumbers = (decimalNumbers * 2) + 1;
        }
    }
}

int main()
{
    int number = 0;

    cout << "Write number: ";
    cin >> number;

    numbersWithDigitInBinaryNotation(number);

    return 0;
}