#include <iostream>
#include <cmath>

using namespace std;

#define N 25

int arrCosmos[][N] = {0};

void createLife();
void showLife();

int main()
{
    createLife();
    showLife();

    return 0;
}

void createLife()
{
    for (int row = 1; row < N - 1; row++)
    {
        for (int column = 1; column < N - 1; column++)
        {
            arrCosmos[row][column] = rand() % 2;
        }
    }
}

void showLife()
{
    for (int row = 1; row < N - 1; row++)
    {
        for (int column = 1; column < N - 1; column++)
        {
            if (arrCosmos[row][column] == 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}