#include <iostream>
#include <cmath>

using namespace std;

int fibonacci(int number);

int main()
{
    int number = 0;

    cout << "Write number: ";
    cin >> number;

    for (int i = 0; i <= number; i++)
    {
        cout << fibonacci(i) << endl;
    }

    return 0;
}

int fibonacci(int number)
{
    if (number < 1)
    {
        return 0;
    }

    if (number == 1 || number == 2)
    {
        return 1;
    }

    return fibonacci(number - 1) + fibonacci(number - 2);
}