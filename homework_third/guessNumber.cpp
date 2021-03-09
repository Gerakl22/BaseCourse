#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int guessNumber = rand() % 1000 + 1, number;

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