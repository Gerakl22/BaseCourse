#include <iostream>
#include <cmath>
#include <time.h>

#define N 3

#define X_CELL char(88) // "X"
#define O_CELL char(79) // "O"

#define EMPTY_CELL char(45) // "_"

using namespace std;

char matrix[][N] = {};

void clearScreen();
void createMatrix();
void showMatrix();
void showRules();

int getNumberFromUser(int number, int row, int column);
int getNumberFromComputer();

bool isWinGame(char cell);
bool isDrawnGame(int row, int column);

int main()
{
    srand(time(NULL));
    int number = 0, row = 0, column = 0;

    createMatrix();

    while (true)
    {

        getNumberFromComputer();

        if (isWinGame(X_CELL))
        {
            cout << "Sorry friend, computer win!" << endl;
            break;
        }

        if (isDrawnGame(row, column))
        {
            cout << "It's drawn in a game!" << endl;
            break;
        }

        showRules();
        showMatrix();

        getNumberFromUser(number, row, column);

        if (isWinGame(O_CELL))
        {
            cout << "Congratulations, you win!" << endl;
            break;
        }

        if (isDrawnGame(row, column))
        {
            cout << "It's drawn in a game!" << endl;
            break;
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

int getNumberFromUser(int number, int row, int column)
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

    return matrix[row][column] = O_CELL;
}

int getNumberFromComputer()
{
    //check the center
    if ((matrix[0][0] == matrix[2][2]) && (matrix[1][1] == EMPTY_CELL))
    {
        return matrix[1][1] = X_CELL;
    }

    if ((matrix[0][2] == matrix[2][0]) && ((matrix[1][1] == EMPTY_CELL)))
    {
        return matrix[1][1] = X_CELL;
    }

    // check row and computer can win
    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][0] == X_CELL) && (matrix[row][1] == matrix[row][0]) && (matrix[row][2] == EMPTY_CELL))
        {
            return matrix[row][2] = X_CELL;
        }
    }

    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][1] == X_CELL) && (matrix[row][2] == matrix[row][1]) && (matrix[row][0] == EMPTY_CELL))
        {
            return matrix[row][0] = X_CELL;
        }
    }

    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][0] == X_CELL) && (matrix[row][2] == matrix[row][0]) && (matrix[row][1] == EMPTY_CELL))
        {
            return matrix[row][1] = X_CELL;
        }
    }

    // check row and computer can defend
    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][0] == O_CELL) && (matrix[row][1] == matrix[row][0]) && (matrix[row][2] == EMPTY_CELL))
        {
            return matrix[row][2] = X_CELL;
        }
    }

    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][1] == O_CELL) && (matrix[row][2] == matrix[row][1]) && (matrix[row][0] == EMPTY_CELL))
        {
            return matrix[row][0] = X_CELL;
        }
    }

    for (int row = 0; row < N; row++)
    {
        if ((matrix[row][0] == O_CELL) && (matrix[row][2] == matrix[row][0]) && (matrix[row][1] == EMPTY_CELL))
        {
            return matrix[row][1] = X_CELL;
        }
    }

    // check column and computer can win
    for (int column = 0; column < N; column++)
    {
        if ((matrix[0][column] == X_CELL) && (matrix[1][column] == matrix[0][column]) && (matrix[2][column] == EMPTY_CELL))
        {
            return matrix[2][column] = X_CELL;
        }
    }

    for (int column = 0; column < N; column++)
    {
        if ((matrix[1][column] == X_CELL) && (matrix[2][column] == matrix[1][column]) && (matrix[0][column] == EMPTY_CELL))
        {
            return matrix[0][column] = X_CELL;
        }
    }

    for (int column = 0; column < N; column++)
    {
        if ((matrix[0][column] == O_CELL || matrix[0][column] == X_CELL) && (matrix[2][column] == matrix[0][column]) && (matrix[1][column] == EMPTY_CELL))
        {
            return matrix[1][column] = X_CELL;
        }
    }

    // check column and computer can defend
    for (int column = 0; column < N; column++)
    {
        if ((matrix[0][column] == O_CELL) && (matrix[1][column] == matrix[0][column]) && (matrix[2][column] == EMPTY_CELL))
        {
            return matrix[2][column] = X_CELL;
        }
    }

    for (int column = 0; column < N; column++)
    {
        if ((matrix[1][column] == O_CELL) && (matrix[2][column] == matrix[1][column]) && (matrix[0][column] == EMPTY_CELL))
        {
            return matrix[0][column] = X_CELL;
        }
    }

    for (int column = 0; column < N; column++)
    {
        if ((matrix[0][column] == O_CELL) && (matrix[2][column] == matrix[0][column]) && (matrix[1][column] == EMPTY_CELL))
        {
            return matrix[1][column] = X_CELL;
        }
    }

    // check diagonal
    if ((matrix[0][0] == matrix[1][1]) && (matrix[2][2] == EMPTY_CELL))
    {
        return matrix[2][2] = X_CELL;
    }

    if ((matrix[2][0] == matrix[1][1]) && (matrix[0][2] == EMPTY_CELL))
    {
        return matrix[0][2] = X_CELL;
    }

    if ((matrix[0][2] == matrix[1][1]) && (matrix[2][0] == EMPTY_CELL))
    {
        return matrix[2][0] = X_CELL;
    }

    if ((matrix[2][2] == matrix[1][1]) && (matrix[0][0] == EMPTY_CELL))
    {
        return matrix[0][0] = X_CELL;
    }

    // begin game if user step on diagonal
    if ((matrix[0][0] == O_CELL || matrix[0][0] == X_CELL) && (matrix[0][1] == matrix[0][2]) && (matrix[0][2] == EMPTY_CELL && matrix[1][1] == X_CELL))
    {
        return matrix[0][2] = X_CELL;
    }

    if ((matrix[0][2] == O_CELL || matrix[0][2] == X_CELL) && (matrix[0][0] == matrix[0][1]) && (matrix[2][2] == EMPTY_CELL && matrix[1][1] == X_CELL))
    {
        return matrix[2][2] = X_CELL;
    }

    if ((matrix[2][0] == O_CELL || matrix[2][0] == X_CELL) && (matrix[2][2] == matrix[2][1]) && (matrix[0][0] == EMPTY_CELL && matrix[1][1] == X_CELL))
    {
        return matrix[0][0] = X_CELL;
    }

    if ((matrix[2][2] == O_CELL || matrix[2][2] == X_CELL) && (matrix[2][0] == matrix[2][1]) && (matrix[2][0] == EMPTY_CELL && matrix[1][1] == X_CELL))
    {
        return matrix[2][0] = X_CELL;
    }

    // finish game if user step on diagonal

    if ((matrix[0][0] == O_CELL || matrix[0][0] == X_CELL) && (matrix[1][0] != EMPTY_CELL) && (matrix[1][1] != EMPTY_CELL) && (matrix[1][2] != EMPTY_CELL) && (matrix[0][1] == EMPTY_CELL))
    {
        return matrix[0][1] = X_CELL;
    }

    if ((matrix[2][0] == O_CELL || matrix[2][0] == X_CELL) && (matrix[0][1] != EMPTY_CELL) && (matrix[1][1] != EMPTY_CELL) && (matrix[2][1] != EMPTY_CELL) && (matrix[1][0] == EMPTY_CELL))
    {
        return matrix[1][0] = X_CELL;
    }

    if ((matrix[0][2] == O_CELL || matrix[0][2] == X_CELL) && (matrix[0][1] != EMPTY_CELL) && (matrix[1][1] != EMPTY_CELL) && (matrix[2][1] != EMPTY_CELL) && (matrix[1][2] == EMPTY_CELL))
    {
        return matrix[1][2] = X_CELL;
    }

    if ((matrix[2][2] == O_CELL || matrix[2][2] == X_CELL) && (matrix[1][0] != EMPTY_CELL) && (matrix[1][1] != EMPTY_CELL) && (matrix[1][2] != EMPTY_CELL) && (matrix[2][1] == EMPTY_CELL))
    {
        return matrix[2][1] = X_CELL;
    }

    // user step to one side

    if ((matrix[0][1] == O_CELL || matrix[1][2] == O_CELL) && (matrix[0][0] == matrix[0][2]) && (matrix[2][0] == EMPTY_CELL))
    {
        return matrix[2][0] = X_CELL;
    }

    if ((matrix[1][0] == O_CELL || matrix[2][2] == O_CELL) && (matrix[2][0] == matrix[2][2]) && (matrix[0][2] == EMPTY_CELL))
    {
        return matrix[0][2] = X_CELL;
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
    cout << "Sorry, computer always will move first";
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
