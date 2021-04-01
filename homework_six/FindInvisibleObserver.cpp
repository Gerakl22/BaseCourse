#include <iostream>
#include <cmath>

using namespace std;

void findInvisibleObserver(int arr[], int N);

int main()
{

    int N = 0;

    cout << "Write length of array: ";
    cin >> N;

    int arr[N] = {};

    for (int i = 0; i < N; i++)
    {
        cout << "Write number " << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << "Array: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    findInvisibleObserver(arr, N);

    return 0;
}

void findInvisibleObserver(int arr[], int N)
{

    double firstPoint = arr[0];
    double distance = arr[1] - arr[0];

    for (int i = 2; i < N; i++)
    {
        if (arr[i] < distance * i + firstPoint)
        {
            cout << i << " " << arr[i] << endl;
        }
        else
        {
            distance = (arr[i] - firstPoint) / i;

        }
    }
}