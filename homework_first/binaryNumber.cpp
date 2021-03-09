#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sum = 0, number = 0, binaryNumber = 0, counter = 0;

    cout << "Please, write binary Number: ";
    cin >> binaryNumber;

    while (binaryNumber > 0)
    {
        number = binaryNumber % 10;
        if (number == 1)
        {
            sum += pow(2, counter);
        }

        counter += 1;
        binaryNumber /= 10;
    }

    cout << "Sum: " << sum << endl;

    return 0;
}