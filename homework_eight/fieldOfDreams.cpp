#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define NUMBER 128

const char guessWord[NUMBER] = "hello";

void clearScreen();
void fillUpHideWordWithStars(char hideWord[]);
void showHideWord(char hideWord[]);

int main()
{
    char hideWord[NUMBER];
    char letter;
    bool isRightLetter = false;
    bool isCloseGame = true;

    fillUpHideWordWithStars(hideWord);

    while (isCloseGame == true)
    {
        showHideWord(hideWord);

        isRightLetter = false;

        cout << "Guess letter from a to z: ";
        cin >> letter;
        cin.ignore(32767, '\n');
        cout << endl;

        clearScreen();

        for (int i = 0; i < guessWord[i] != '\0'; i++)
        {
            if (guessWord[i] == letter)
            {
                hideWord[i] = letter;
                isRightLetter = true;
            }
        }

        ((isRightLetter == true) ? cout << "There is such a letter in this word!" << endl : cout << "Here! There is no such letter!" << endl);

        for (int i = 0; hideWord[i] != '\0'; i++)
        {
            if (hideWord[i] == '*')
            {
                isCloseGame = true;
                break;
            }
            else
            {
                isCloseGame = false;
            }
        }
    }

    showHideWord(hideWord);
    cout << "You are winner!" << endl;

    return 0;
}

void clearScreen()
{
    system("cls");
}

void fillUpHideWordWithStars(char hideWord[])
{
    for (int i = 0; guessWord[i] != '\0'; i++)
    {
        hideWord[i] = '*';
    }
}

void showHideWord(char hideWord[])
{
    cout << endl;
    cout << "This word is " << hideWord << endl;
    cout << endl;
}
