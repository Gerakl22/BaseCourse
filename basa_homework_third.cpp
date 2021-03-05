#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    // 3. ЦИФРА. Распечатайте первую цифру из дробной части вещественного положительного числа.
    double x = 0;
    int y = 0;

    cout << "Write number: ";
    cin >> x;

    y = x * 10;
    y = y % 10;

    cout << y << endl;

    // 4. УГАДАЙ ЧИСЛО. Разработайте игру: компьютер загадывает число и выдает подсказки ("больше-меньше") пользователю.
    int thinkOfNumber = 25, num;

    cout << "Write number: ";
    cin >> num;

    while (thinkOfNumber != num)
    {

        if (thinkOfNumber > num)
        {
            cout << "Write a bigger number: ";
            cin >> num;
        }
        else
        {
            cout << "Write a smallest number: ";
            cin >> num;
        }
    }

    cout << "Congratulations!!! You guess right number" << endl;

    return 0;
}
