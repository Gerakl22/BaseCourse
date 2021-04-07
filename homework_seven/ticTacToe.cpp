#include <iostream>
#include <cmath>
#include <time.h>

#define N 3
#define X_CELL char(88)     // "X"
#define O_CELL char(79)     // "O"
#define EMPTY_CELL char(45) // "_"

using namespace std;

char matrix[][N] = {};

void clearScreen();
void createMatrix();
void showMatrix();
void showRules();

int getNumberFromComputer(char cell);
int getNumberFromUser(char cell, int number, int row, int column);

bool isDrawnGame(int row, int column);
bool isWinGame(char cell);

int main()
{
    srand(time(NULL));
    int number = 0, row = 0, column = 0, randomNumber = -1;
    char cellXComputer, cellOUser, cellXUser, cellOComputer;

    randomNumber = rand() % 2;

    if (randomNumber == 0)
    {
        cellXComputer = X_CELL;
        cellOUser = O_CELL;
    }
    else
    {
        cellXUser = X_CELL;
        cellOComputer = O_CELL;
    }

    createMatrix();

    while (true)
    {
        if (randomNumber == 0)
        {
            getNumberFromComputer(cellXComputer);

            if (isWinGame(cellXComputer))
            {
                cout << "Sorry friend, computer win!" << endl;
                showMatrix();
                break;
            }

            if (isDrawnGame(row, column))
            {
                cout << "It's drawn in a game!" << endl;
                showMatrix();
                break;
            }

            showRules();
            showMatrix();

            getNumberFromUser(cellOUser, number, row, column);

            if (isWinGame(cellOUser))
            {
                cout << "Congratulations, you win!" << endl;
                showMatrix();
                break;
            }

            if (isDrawnGame(row, column))
            {
                cout << "It's drawn in a game!" << endl;
                showMatrix();
                break;
            }
        }
        else
        {
            showRules();
            showMatrix();

            getNumberFromUser(cellXUser, number, row, column);

            if (isWinGame(cellXUser))
            {
                cout << "Congratulations, you win!" << endl;
                showMatrix();
                break;
            }

            if (isDrawnGame(row, column))
            {
                cout << "It's drawn in a game!" << endl;
                showMatrix();
                break;
            }

            getNumberFromComputer(cellOComputer);

            if (isWinGame(cellOComputer))
            {
                cout << "Sorry friend, computer win!" << endl;
                showMatrix();
                break;
            }

            if (isDrawnGame(row, column))
            {
                cout << "It's drawn in a game!" << endl;
                showMatrix();
                break;
            }
        }
    }

    return 0;
}

bool isDrawnGame(int row, int column)
{
    for (int row = 0; row < N; row++)
    {
        for (int column = 0; column < N; column++)
        {
            if (matrix[row][column] == EMPTY_CELL)
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

int getNumberFromUser(char cell, int number, int row, int column)
{
    while (matrix[row][column] == X_CELL || matrix[row][column] == O_CELL || number < 1 || number > 9)
    {
        cout << "Please, write number from 1 to 9: ";
        cin >> number;
        cout << endl;

        clearScreen();

        if (number % N == 0)
        {
            row = number / N - 1;
            column = N - 1;
        }
        else
        {
            row = number / N;
            column = number % 3 - 1;
        }
    }

    return matrix[row][column] = cell;
}

int getNumberFromComputer(char cell)
{
    int randRow = 0, randColumn = 0;

    //check the center
    if ((matrix[0][0] == matrix[2][2]) && (matrix[1][1] == EMPTY_CELL))
    {
        return matrix[1][1] = cell;
    }

    if ((matrix[0][2] == matrix[2][0]) && ((matrix[1][1] == EMPTY_CELL)))
    {
        return matrix[1][1] = cell;
    }

    if ((matrix[1][1] != EMPTY_CELL) && (matrix[0][0] == matrix[0][2]) && (matrix[2][0] == matrix[2][2]) && (matrix[0][0] == EMPTY_CELL))
    {
        randRow = rand() % 3;
        randColumn = rand() % 3;

        return matrix[randRow][randColumn] = cell;
    }

    // check row and computer can win
    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][0] == cell) && (matrix[row][1] == matrix[row][0]) && (matrix[row][2] == EMPTY_CELL))
        {
            return matrix[row][2] = cell;
        }
    }

    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][1] == cell) && (matrix[row][2] == matrix[row][1]) && (matrix[row][0] == EMPTY_CELL))
        {
            return matrix[row][0] = cell;
        }
    }

    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][0] == cell) && (matrix[row][2] == matrix[row][0]) && (matrix[row][1] == EMPTY_CELL))
        {
            return matrix[row][1] = cell;
        }
    }

    // check row and computer can defend
    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][0] != EMPTY_CELL) && (matrix[row][1] == matrix[row][0]) && (matrix[row][2] == EMPTY_CELL))
        {
            return matrix[row][2] = cell;
        }
    }

    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][1] != EMPTY_CELL) && (matrix[row][2] == matrix[row][1]) && (matrix[row][0] == EMPTY_CELL))
        {
            return matrix[row][0] = cell;
        }
    }

    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][0] != EMPTY_CELL) && (matrix[row][2] == matrix[row][0]) && (matrix[row][1] == EMPTY_CELL))
        {
            return matrix[row][1] = cell;
        }
    }

    // check column and computer can win
    for (int column = 0; column < N; column++)
    {
        if ((matrix[0][column] == cell) && (matrix[1][column] == matrix[0][column]) && (matrix[2][column] == EMPTY_CELL))
        {
            return matrix[2][column] = cell;
        }
    }

    for (int column = 0; column < N; column++)
    {
        if ((matrix[1][column] == cell) && (matrix[2][column] == matrix[1][column]) && (matrix[0][column] == EMPTY_CELL))
        {
            return matrix[0][column] = cell;
        }
    }

    for (int column = 0; column < N; column++)
    {
        if ((matrix[0][column] != EMPTY_CELL || matrix[0][column] == cell) && (matrix[2][column] == matrix[0][column]) && (matrix[1][column] == EMPTY_CELL))
        {
            return matrix[1][column] = cell;
        }
    }

    // check column and computer can defend
    for (int column = 0; column < N; column++)
    {
        if ((matrix[0][column] != EMPTY_CELL) && (matrix[1][column] == matrix[0][column]) && (matrix[2][column] == EMPTY_CELL))
        {
            return matrix[2][column] = cell;
        }
    }

    for (int column = 0; column < N; column++)
    {
        if ((matrix[1][column] != EMPTY_CELL) && (matrix[2][column] == matrix[1][column]) && (matrix[0][column] == EMPTY_CELL))
        {
            return matrix[0][column] = cell;
        }
    }

    for (int column = 0; column < N; column++)
    {
        if ((matrix[0][column] != EMPTY_CELL) && (matrix[2][column] == matrix[0][column]) && (matrix[1][column] == EMPTY_CELL))
        {
            return matrix[1][column] = cell;
        }
    }

    // check diagonal
    if ((matrix[0][0] == matrix[1][1]) && (matrix[2][2] == EMPTY_CELL))
    {
        return matrix[2][2] = cell;
    }

    if ((matrix[2][0] == matrix[1][1]) && (matrix[0][2] == EMPTY_CELL))
    {
        return matrix[0][2] = cell;
    }

    if ((matrix[0][2] == matrix[1][1]) && (matrix[2][0] == EMPTY_CELL))
    {
        return matrix[2][0] = cell;
    }

    if ((matrix[2][2] == matrix[1][1]) && (matrix[0][0] == EMPTY_CELL))
    {
        return matrix[0][0] = cell;
    }

    // begin game if user step on diagonal
    if ((matrix[0][0] != EMPTY_CELL || matrix[0][0] == cell) && (matrix[0][1] == matrix[0][2]) && (matrix[0][2] == EMPTY_CELL && matrix[1][1] == cell))
    {
        return matrix[0][2] = cell;
    }

    if ((matrix[0][2] != EMPTY_CELL || matrix[0][2] == cell) && (matrix[0][0] == matrix[0][1]) && (matrix[2][2] == EMPTY_CELL && matrix[1][1] == cell))
    {
        return matrix[2][2] = cell;
    }

    if ((matrix[2][0] != EMPTY_CELL || matrix[2][0] == cell) && (matrix[2][2] == matrix[2][1]) && (matrix[0][0] == EMPTY_CELL && matrix[1][1] == cell))
    {
        return matrix[0][0] = cell;
    }

    if ((matrix[2][2] != EMPTY_CELL || matrix[2][2] == cell) && (matrix[2][0] == matrix[2][1]) && (matrix[2][0] == EMPTY_CELL && matrix[1][1] == cell))
    {
        return matrix[2][0] = cell;
    }

    // finish game if user step on diagonal

    if ((matrix[0][0] != EMPTY_CELL || matrix[0][0] == cell) && (matrix[1][0] != EMPTY_CELL) && (matrix[1][1] != EMPTY_CELL) && (matrix[1][2] != EMPTY_CELL) && (matrix[0][1] == EMPTY_CELL))
    {
        return matrix[0][1] = cell;
    }

    if ((matrix[2][0] != EMPTY_CELL || matrix[2][0] == cell) && (matrix[0][1] != EMPTY_CELL) && (matrix[1][1] != EMPTY_CELL) && (matrix[2][1] != EMPTY_CELL) && (matrix[1][0] == EMPTY_CELL))
    {
        return matrix[1][0] = cell;
    }

    if ((matrix[0][2] != EMPTY_CELL || matrix[0][2] == cell) && (matrix[0][1] != EMPTY_CELL) && (matrix[1][1] != EMPTY_CELL) && (matrix[2][1] != EMPTY_CELL) && (matrix[1][2] == EMPTY_CELL))
    {
        return matrix[1][2] = cell;
    }

    if ((matrix[2][2] != EMPTY_CELL || matrix[2][2] == cell) && (matrix[1][0] != EMPTY_CELL) && (matrix[1][1] != EMPTY_CELL) && (matrix[1][2] != EMPTY_CELL) && (matrix[2][1] == EMPTY_CELL))
    {
        return matrix[2][1] = cell;
    }

    // user step to one side

    if ((matrix[0][1] != EMPTY_CELL || matrix[1][2] != EMPTY_CELL) && (matrix[0][0] == matrix[0][2]) && (matrix[2][0] == EMPTY_CELL))
    {
        return matrix[2][0] = cell;
    }

    if ((matrix[1][0] != EMPTY_CELL || matrix[2][2] != EMPTY_CELL) && (matrix[2][0] == matrix[2][2]) && (matrix[0][2] == EMPTY_CELL))
    {
        return matrix[0][2] = cell;
    }
}

void createMatrix()
{
    for (int row = 0; row < N; row++)
    {
        for (int column = 0; column < N; column++)
        {
            matrix[row][column] = EMPTY_CELL;
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

    cout << "This is game of tic-tac-toe and you will play against computer";
    cout << endl;
    cout << "You have to choose option and it will you move game: ";
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
