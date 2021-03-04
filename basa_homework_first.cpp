#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{

    // 1. МУТАНТЫ. Ночью на Минск напало m мутантов.
    // Каждую ночь они размножаются на p процентов.
    // Каждый день коммунальные службы Минска уничтожают n мутантов.
    // Через сколько суток работники ЖЭСа отпразднуют победу над мутантами?
    int n = 0, day = 0;
    double m = 0, p = 0;

    cout << "Please, write number of mutants: ";
    cin >> m;
    cout << "Please, write how much percent of increase mutants?: ";
    cin >> p;
    cout << "Please, write how much mutants need to delete?: ";
    cin >> n;

    while (m > 0)
    {
        m = (((m * p) / 100) + m) - n;
        day++;
    }

    cout << "Day: " << day << endl;

    // 2. КОНИ. Вводим 4 целых числа.
    // Это координаты двух коней на шахматной доске.
    // Бьют ли они друг друга?
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    cout << "Please, write position x for white knight: ";
    cin >> x1;
    cout << "Please, write postion y for white knight: ";
    cin >> y1;
    cout << "Please, write position x for black knight: ";
    cin >> x2;
    cout << "Please, write position y for black knight: ";
    cin >> y2;

    if (abs(x1 - x2) * abs(y1 - y2) == 2)
    {
        cout << "Kick knight" << endl;
    }
    else
    {
        cout << "No kick knight" << endl;
    }

    // [+]. Переведите число из двоичной системы в десятичную.
    // int binaryNumber = 10010111; //151
    // int binaryNumber = 1101010; // 106
    int i = 0, sum = 0, number = 0, binaryNumber = 0;

    cout << "Please, write binary Number: ";
    cin >> binaryNumber;

    while (binaryNumber > 0)
    {
        number = binaryNumber % 10;
        cout << binaryNumber << endl;
        if (number == 1)
        {
            sum += pow(2, i);
        };
        i += 1;
        binaryNumber /= 10;
    }

    cout << "Sum: " << sum << endl;

    return 0;
}
