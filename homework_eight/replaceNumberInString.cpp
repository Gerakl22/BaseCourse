#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define NUMBER 128
#define PLUS '+'
#define MINUS '-'

void replaceNumberInString(char string[]);

int main()
{
    char string[NUMBER] = "1f5a4f3s0d1";

    replaceNumberInString(string);

    return 0;
}

void replaceNumberInString(char string[])
{
    char replaceArr[NUMBER];
    int number = 0, index = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= '0' && string[i] <= '9')
        {
            number = string[i] - '0';

            if (number == 0)
            { 
                replaceArr[index] = ' ';
            }

            if (number % 2 == 0)
            {
                for (int j = 0; j < number; j++)
                {
                    replaceArr[index++] = PLUS;
                }
            }
            else
            {
                for (int j = 0; j < number; j++)
                {
                    replaceArr[index++] = MINUS;
                }
            }
        }
        else
        {
            replaceArr[index++] = string[i];
        }
    }
    replaceArr[index] = '\0';

    cout << replaceArr;
}