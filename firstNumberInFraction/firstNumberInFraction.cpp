#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    double number = 0;
    int tmp = 0;

    cout << "Write number: ";
    cin >> number;

    tmp = number * 10;
    tmp = tmp % 10;

    cout << "First number in Fraction: " << tmp << endl;

    return 0;
}