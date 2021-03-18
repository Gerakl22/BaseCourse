#include <iostream>
#include <cmath>

using namespace std;

int sumNumbersDayOrMonth(int number);
int sumNumbersDateOfBirth(int day, int month, int year);

int main()
{
    int day = 0, month = 0, year = 0;

    cout << "Write my day of birthday: ";
    cin >> day;
    cout << "Write my month of birthday: ";
    cin >> month;
    cout << "Write my year of birthday: ";
    cin >> year;

    cout << sumNumbersDateOfBirth(day, month, year) << endl;

    return 0;
}

int sumNumbersDayOrMonth(int number)
{
    return number / 10 + number % 10;
}

int sumNumbersDateOfBirth(int day, int month, int year)
{
    day = sumNumbersDayOrMonth(day);
    month = sumNumbersDayOrMonth(month);
    year = year / 1000 + ((year / 100) % 10) + ((year / 10) % 10) + year % 10;

    return day + month + year;
}
