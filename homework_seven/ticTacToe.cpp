#include <iostream>
#include <cmath>
#include <time.h>

#define N 3

#define X_CELL char(88) // "X"
#define O_CELL char(79) // "O"

#define EMPTY_CELL char(45) // "_"

using namespace std;

char matrix[N][N] = {};

void clearScreen();
void createMatrix();
void showMatrix();
void showRules();

int getNumberFromUser(int number, int selectRow, int selectColumn);
int getNumberFromComputer(int number, int selectRow, int selectColumn);

bool isWinGame(char cell);
bool isDrawnGame(int selectRow, int selectColumn);

int main()
{
    srand(time(NULL));

    int number = 0, selectRow = 0, selectColumn = 0;

    showRules();

    createMatrix();

    while (true)
    {
        getNumberFromUser(number, selectRow, selectColumn);

        if (isWinGame(X_CELL))
        {
            cout << "Congratulations, you win!" << endl;
            break;
        }

        if (isDrawnGame(selectRow, selectColumn))
        {
            cout << "It's drawn in a game!" << endl;
            break;
        }

        getNumberFromComputer(number, selectRow, selectColumn);

        if (isWinGame(O_CELL))
        {
            cout << "Congratulations, computer win!" << endl;
            break;
        }

        if (isDrawnGame(selectRow, selectColumn))
        {
            cout << "It's drawn in a game!" << endl;
            break;
        }

        showRules();
        showMatrix();
    }

    return 0;
}

bool isDrawnGame(int selectRow, int selectColumn)
{
    for (int selectRow = 0; selectRow < N; selectRow++)
    {
        for (int selectColumn = 0; selectColumn < N; selectColumn++)
        {
            if (matrix[selectRow][selectColumn] == EMPTY_CELL)
            {
                return false;
            }
        }
    }

    return true;
}

bool isWinGame(char cell)
{
    for (int row = 0; row < N; row++)
    {
        if (matrix[row][0] == cell && matrix[row][1] == cell && matrix[row][2] == cell)
        {
            return true;
        }
    }

    for (int column = 0; column < N; column++)
    {
        if (matrix[0][column] == cell && matrix[1][column] == cell && matrix[2][column] == cell)
        {
            return true;
        }
    }

    if ((matrix[0][0] == cell && matrix[1][1] == cell && matrix[2][2] == cell) || (matrix[0][2] == cell && matrix[1][1] == cell && matrix[2][0] == cell))
    {
        return true;
    }

    return false;
}

int getNumberFromUser(int number, int selectRow, int selectColumn)
{

    cout << "Please, write number from 1 to 9: ";
    cin >> number;
    cout << endl;

    clearScreen();

    if (number < 1 || number > 9)
    {
        return false;
    }

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

    if (matrix[selectRow][selectColumn] == X_CELL || matrix[selectRow][selectColumn] == O_CELL)
    {
        return false;
    }
    else
    {
        matrix[selectRow][selectColumn] = X_CELL;
    }
}

int getNumberFromComputer(int number, int selectRow, int selectColumn)
{
    while ((matrix[selectRow][selectColumn] == X_CELL || matrix[selectRow][selectColumn] == O_CELL))
    {
        number = 1 + rand() % 9;

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
    }

    matrix[selectRow][selectColumn] = O_CELL;
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