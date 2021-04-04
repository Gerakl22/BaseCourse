#include <iostream>
#include <cmath>
#include <time.h>

#define N 3

using namespace std;

int checkGleamInCubeOnAxisX(int cube[N][N][N], int gleam);
int checkGleamInCubeOnAxisY(int cube[N][N][N], int gleam);
int checkGleamInCubeOnAxisZ(int cube[N][N][N], int gleam);

int main()
{
    srand(time(NULL));

    int cube[N][N][N] = {0}, gleam = 0;

    for (int xCoord = 0; xCoord < N; xCoord++)
    {
        for (int yCoord = 0; yCoord < N; yCoord++)
        {
            for (int zCoord = 0; zCoord < N; zCoord++)
            {
                cube[xCoord][yCoord][zCoord] = rand() % 2;

                cout << cube[xCoord][yCoord][zCoord];
            }
            cout << endl;
        }
        cout << endl;
    }

    gleam = checkGleamInCubeOnAxisX(cube, gleam) + checkGleamInCubeOnAxisY(cube, gleam) + checkGleamInCubeOnAxisZ(cube, gleam);

    if (gleam > 0)
    {
        cout << "There is " << gleam << " gleam in cube!" << endl;
    }
    else
    {
        cout << "There is no gleam in cube" << endl;
    }

    return 0;
}

int checkGleamInCubeOnAxisX(int cube[N][N][N], int gleam)
{
    for (int yCoord = 0; yCoord < N; yCoord++)
    {
        for (int zCoord = 0; zCoord < N; zCoord++)
        {
            int counter = 0;

            for (int xCoord = 0; xCoord < N; xCoord++)
            {
                counter += cube[xCoord][yCoord][zCoord];
            }

            if (counter == 0)
            {
                gleam += 1;
            }
        }
    }

    return gleam;
}

int checkGleamInCubeOnAxisY(int cube[N][N][N], int gleam)
{
    for (int zCoord = 0; zCoord < N; zCoord++)
    {
        for (int xCoord = 0; xCoord < N; xCoord++)
        {
            int counter = 0;

            for (int yCoord = 0; yCoord < N; yCoord++)
            {
                counter += cube[xCoord][yCoord][zCoord];
            }

            if (counter == 0)
            {
                gleam += 1;
            }
        }
    }

    return gleam;
}

int checkGleamInCubeOnAxisZ(int cube[N][N][N], int gleam)
{
    for (int xCoord = 0; xCoord < N; xCoord++)
    {
        for (int yCoord = 0; yCoord < N; yCoord++)
        {
            int counter = 0;

            for (int zCoord = 0; zCoord < N; zCoord++)
            {
                counter += cube[xCoord][yCoord][zCoord];
            }

            if (counter == 0)
            {
                gleam += 1;
            }
        }
    }

    return gleam;
}
