#include <iostream>
#include <cmath>

using namespace std;

void changePositionOfRecruits(string arr[], int N);

int main()
{

    int N = 0;

    cout << "Write length of array: ";
    cin >> N;

    string arr[N] = {};

    for (int i = 0; i < N; i++)
    {
        cout << "Write recruit " << i + 1 << " : ";
        cin >> arr[i];
    };

    changePositionOfRecruits(arr, N);

    cout << "Array: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void changePositionOfRecruits(string arr[], int N)
{
    int stopChangePostion = 9;

    while (stopChangePostion != 0)
    {
        for (int i = 1; i < N; i++)
        {
            if (arr[i - 1] != arr[i])
            {
                string temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                i++;
            }
        }

        stopChangePostion--;
    }
}