#include <iostream>
#include <cmath>
#include <time.h>

#define N 3

#define SELECT_X char(88) // "X"
#define SELECT_O char(79) // "O"

#define EMPTY_CELL char(45) // "_"

using namespace std;

char matrix[N][N] = {};

void clearScreen();
void createMatrix();
void showMatrix();
void showRules();

int getNumberFromUser(int &number, int &selectRow, int &selectColumn);

bool isCellCorrect(int &number);
bool isCellEmpty(int &selectRow, int &selectColumn);

int main()
{
    srand(time(NULL));

    int number = 0, selectRow = 0, selectColumn = 0;

    showRules();

    createMatrix();

    while (true)
    {

        getNumberFromUser(number, selectRow, selectColumn);
        showRules();
        showMatrix();
    }

    return 0;
}

bool isCellCorrect(int &number)
{
    if (number < 1 && number > 9)
    {
        return false;
    }
}

bool isCellEmpty(int &selectRow, int &selectColumn)
{
    if (matrix[selectRow][selectColumn] == SELECT_X && matrix[selectRow][selectColumn] == SELECT_O)
    {
        return false;
    }
}

int getNumberFromUser(int &number, int &selectRow, int &selectColumn)
{
    cout << "Please, write number from 1 to 9: ";
    cin >> number;
    cout << endl;

    clearScreen();
    isCellCorrect(number);

    if (number % N == 0)
    {
        selectRow = number / N - 1;
        selectColumn = N - 1;
    }
    else
    {
        selectRow = number / N;
        selectColumn = number % 3 - 1;
    }

    isCellEmpty(selectRow, selectColumn);

    matrix[selectRow][selectColumn] = SELECT_X;
}

void createMatrix()
{
    for (int row = 0; row < N; row++)
    {
        for (int column = 0; column < N; column++)
        {
            matrix[row][column] = EMPTY_CELL;
            cout << matrix[row][column] << " ";
        }
        cout << endl;
    }
}

void clearScreen()
{
    system("cls");
}

void showMatrix()
{
    for (int row = 0; row < N; row++)
    {
        for (int column = 0; column < N; column++)
        {
            cout << matrix[row][column] << " ";
        }
        cout << endl;
    }
}

void showRules()
{
    int counter = 1;
    int arr[N][N] = {};

    cout << "This is game of tic-tac-toe and you will play against computer" << endl;
    cout << endl;
    cout << "You have to choose option and it will you game move: ";
    cout << endl;

    cout << "__________" << endl;
    for (int row = 0; row < N; row++)
    {
        for (int column = 0; column < N; column++)
        {
            cout << "|";
            arr[row][column] += counter;

            counter++;
            cout << arr[row][column] << " ";
        }
        cout << "|";
        cout << endl;
        cout << "__________" << endl;
    }

    cout << endl;
    cout << "Good luck!";
    cout << endl;
    cout << endl;
};