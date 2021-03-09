#include <iostream>

using namespace std;

int main()
{
    double numberOfMutants = 0, percentMultiplicationOfMutants = 0;
    int killMutants = 0, daysForVictoryOverMutants = 0;

    cout << "Please, write number of mutants: ";
    cin >> numberOfMutants;
    cout << "Please, write how much percent of increase mutants: ";
    cin >> percentMultiplicationOfMutants;
    cout << "Please, write how much mutants need to kill: ";
    cin >> killMutants;

    while (numberOfMutants > 0)
    {
        numberOfMutants = (((numberOfMutants * percentMultiplicationOfMutants) / 100) + numberOfMutants) - killMutants;
        daysForVictoryOverMutants++;
    }

    cout << "Days for victory over mutants: " << daysForVictoryOverMutants << endl;

    return 0;
}
