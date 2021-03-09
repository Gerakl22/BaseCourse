#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int xCoordForWhiteKnight = 0, yCoordForWhiteKnight = 0, xCoordForBlackKnight = 0, yCoordForBlackKnight = 0;

    cout << "Please, write x coordinate for white knight: ";
    cin >> xCoordForWhiteKnight;
    cout << "Please, write y coordinate for white knight: ";
    cin >> yCoordForWhiteKnight;
    cout << "Please, write x coordinate for black knight: ";
    cin >> xCoordForBlackKnight;
    cout << "Please, write y coordinate for black knight: ";
    cin >> yCoordForBlackKnight;

    if (abs(xCoordForWhiteKnight - xCoordForBlackKnight) * abs(yCoordForWhiteKnight - yCoordForBlackKnight) == 2)
    {
        cout << "Kick knight" << endl;
    }
    else
    {
        cout << "No kick knight" << endl;
    }

    return 0;
}
