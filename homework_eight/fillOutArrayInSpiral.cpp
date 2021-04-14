#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

// #define NUMBER 3
#define NUMBER 4
// #define NUMBER 5
#define NUMBERCHAR 256

int getCounterWord(char word[]);

int main()
{
    // char word[NUMBERCHAR] = "findwomen";
    char word[NUMBERCHAR] = "helloworldletter";
    // char word[NUMBERCHAR] = "helloworldletterglobalcat";
    char spiral[NUMBER][NUMBER] = {0};

    int matrixOfNumbers = NUMBER * NUMBER;
    int counterSpiral = getCounterWord(word);

    if (matrixOfNumbers % 2 == 1)
    {
        spiral[NUMBER / 2][NUMBER / 2] = word[0];
        counterSpiral--;
    }
    else
    {
        spiral[NUMBER / 2][NUMBER / 2 - 1] = word[0];
        counterSpiral--;
    }

    for (int row = row; row < NUMBER / 2; row++)
    {
        // top
        for (int column = row; column < NUMBER - row - 1; column++)
        {
            spiral[row][column] = word[counterSpiral--];
            matrixOfNumbers--;
        }

        // right
        for (int column = row; column < NUMBER - row - 1; column++)
        {
            spiral[column][NUMBER - row - 1] = word[counterSpiral--];
            matrixOfNumbers--;
        }

        // bottom
        for (int column = row; column < NUMBER - row - 1; column++)
        {
            spiral[NUMBER - row - 1][NUMBER - column - 1] = word[counterSpiral--];
            matrixOfNumbers--;
        }

        // left
        for (int column = row; column < NUMBER - row - 1; column++)
        {
            spiral[NUMBER - column - 1][row] = word[counterSpiral--];
            matrixOfNumbers--;
        }
    }

    for (int i = 0; i < NUMBER; i++)
    {
        for (int j = 0; j < NUMBER; j++)
        {
            cout << " " << spiral[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

int getCounterWord(char word[])
{
    int counterWord = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        counterWord++;
    }

    return counterWord;
}