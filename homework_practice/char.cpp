#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

// 1) strLen()
// 2)  strCpy()
// 3) strCat()
// 4) strCmp()
// 5) isLetter()
// 6) isWord()
// 7) strToInt()

// char 0 - 48

// int i = "\0" and the same int i = 0

#define NUMBER 128

int strLen(char string[]);
void strCpy(char copyString[], char userString[]);
void strCat(char fistConcatString[], char secondConcatString[]);
int strCmp(char firstString[], char secondString[]);
int strToInt(char number[]);

bool isLetter(char letter);
bool isWord(char word[]);

int main()
{
    char string[NUMBER] = "Hello";

    char copyString[NUMBER];
    char userString[NUMBER] = "Hi";

    char firstConcatString[NUMBER] = "Hello ";
    char secondConcatString[] = "World";

    char firstString[NUMBER] = "logo";
    char secondString[NUMBER] = "card";

    char letter = 'D';
    char word[NUMBER] = "STORE";

    char number[NUMBER] = "12345";

    cout << strLen(string) << endl;
    strCpy(copyString, userString);
    strCat(firstConcatString, secondConcatString);
    cout << strCmp(firstString, secondString) << endl;
    cout << ((isLetter(letter)) ? "Yes" : "No") << endl;
    cout << ((isWord(word)) ? "Yes" : "No") << endl;
    cout << strToInt(number) << endl;

    return 0;
}

int strLen(char string[])
{
    int count = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

void strCpy(char copyString[], char userString[])
{
    for (int i = 0; userString[i] != '\0'; i++)
    {
        copyString[i] = userString[i];
    }

    cout << copyString << endl;
}

void strCat(char firstConcatString[], char secondConcatString[])
{
    int firstCounter = 0, secondCounter = 0;

    for (int i = 0; i < firstConcatString[i] != '\0'; i++)
    {
        firstCounter++;
    }

    for (int j = 0; j < secondConcatString[j] != '\0'; j++)
    {
        firstConcatString[firstCounter] = secondConcatString[secondCounter];
        firstCounter++;
        secondCounter++;
    }

    cout << firstConcatString << endl;
}

int strCmp(char firstString[], char secondString[])
{
    for (int i = 0; i < firstString[i] != '\0'; i++)
    {
        if (firstString[i] > secondString[i])
        {
            return 1;
        }
        else if (firstString[i] < secondString[i])
        {
            return -1;
        }
    }

    return 0;
}

bool isLetter(char letter)
{
    if (letter >= 'A' && letter < 'Z')
    {
        return true;
    }

    return false;
}

bool isWord(char word[])
{
    for (int i = 0; i < word[i] != '\0'; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            return true;
        }
    }

    return false;
}

int strToInt(char number[])
{
    int newNumber = 0;
    for (int i = 0; i < number[i] != '\0'; i++)
    {
        newNumber = newNumber * 10 + number[i] - '0';
    }

    return newNumber;
}