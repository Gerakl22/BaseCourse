#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // 1. НОК. Найдите наименьшее общее кратное двух натуральных чисел.
    // Example: x = 15; y = 10; multiplication = 150; NOK = 30
    int x = 0, y = 0, multiplication = 0;

    cout << "Write first number: ";
    cin >> x;
    cout << "Write second number: ";
    cin >> y;

    multiplication = x * y;

    while (x != y)
    {
        if (x > y)
        {
            x = x - y;
        }
        else
        {
            y = y - x;
        }
    }

    cout << "Min common multiple: " << multiplication / x << endl;

    // 2. ТРЕУГОЛЬНИК. Заданы три числа. Выясните,  какого вида треугольник с такими длинами сторон:
    // равносторонний, прямоугольный, равнобедренный или общего вида.

    int x = 0, y = 0, z = 0;

    cout << "Write number x: ";
    cin >> x;
    cout << "Write number y: ";
    cin >> y;
    cout << "Write number z: ";
    cin >> z;

    if (x == y && x == z && y == z)
    {
        cout << "It's equal triangle";
    }
    else if ((x == y && y != z) || (x == z && z != y) || (y == z && z != x))
    {
        cout << "It's equicrural trienagle";
    }
    else if (((pow(x, 2) + pow(y, 2)) == pow(z, 2)) ||
             ((pow(x, 2) + pow(z, 2)) == pow(y, 2)) ||
             ((pow(z, 2) + pow(y, 2)) == pow(x, 2)))
    {
        cout << "It's rectangle triangle";
    }
    else
    {
        cout << "It's scalene triangle";
    }

    return 0;
}