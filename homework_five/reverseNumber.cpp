#include <iostream>
#include <cmath>

using namespace std;

int reverseNumber(int number);

int main()
{
    int number = 0;

    cout << "Write number: ";
    cin >> number;

    cout << reverseNumber(number) << endl;

    return 0;
}

int reverseNumber(int number)
{
    int reverseNumber = 0;

    while (number != 0)
    {
        reverseNumber = (number % 10) + reverseNumber * 10;
        number /= 10;
    }

    return reverseNumber;
}