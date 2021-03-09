#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int guessNumber = 25, number = 0;

    cout << "Write number: ";
    cin >> number;

    while (guessNumber != number)
    {
        if (guessNumber > number)
        {
            cout << "Write a bigger number: ";
            cin >> number;
        }
        else
        {
            cout << "Write a smallest number: ";
            cin >> number;
        }
    }

    cout << "Congratulations!!! You guess right number" << endl;

    return 0;
}