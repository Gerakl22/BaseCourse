#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int firstSide = 0, secondSide = 0, thirdSide = 0;

    cout << "Write first side of triangle: ";
    cin >> firstSide;
    cout << "Write second side of triangle: ";
    cin >> secondSide;
    cout << "Write third side of triangle: ";
    cin >> thirdSide;

    if (firstSide == secondSide && firstSide == thirdSide && secondSide == thirdSide)
    {
        cout << "It's equal triangle";
    }
    else if ((firstSide == secondSide && secondSide != thirdSide) || (firstSide == thirdSide && thirdSide != secondSide) || (secondSide == thirdSide && thirdSide != firstSide))
    {
        cout << "It's equicrural trienagle";
    }
    else if (((pow(firstSide, 2) + pow(secondSide, 2)) == pow(thirdSide, 2)) ||
             ((pow(firstSide, 2) + pow(thirdSide, 2)) == pow(secondSide, 2)) ||
             ((pow(thirdSide, 2) + pow(secondSide, 2)) == pow(firstSide, 2)))
    {
        cout << "It's rectangle triangle";
    }
    else
    {
        cout << "It's scalene triangle";
    }

    return 0;
}