#include <iostream>
#include <cmath>

using namespace std;

void raiseToAPower(int number, int degree);

int main()
{
    int number = 0, degree = 0;

    cout << "Write number: ";
    cin >> number;
    cout << "Write degree: ";
    cin >> degree;

    raiseToAPower(number, degree);

    return 0;
}

void raiseToAPower(int number, int degree)
{
    int sum = 1;
    for (int i = 1; i <= degree; i++)
    {
        sum *= number;
    }

    cout << "Raised number: " << sum << endl;
}