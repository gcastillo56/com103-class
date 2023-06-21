/* Filename: ultimate.cpp
 *
 * This program showcases the integration of a program with multiple files.
 * We have a header, a file where we implement, and finally this file that
 * uses it all.
 *
 * @author: gcastill
 * August 2023
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "characters.h"
using namespace std;

const string FILENAME = "characters.dat";

int main()
{
    // Initialize randomization
    srand(time(0));
    hero myHero;
    enemy myEnemy;
    Character third;
    int opt;

    do
    {
        cout << "What do you want to do?\n"
             << "1. Create & save characters\n"
             << "2. Load character from file\n"
             << ": ";
        cin >> opt;
        if (opt < 1 || opt > 2)
        {
            cout << "Invalid option\n\n";
        }
    } while (opt < 1 || opt > 2);

    if (opt == 1)
    {
        myHero = getAlly();
        myEnemy = getEnemy();
        third = getThird();

        ofstream wf(FILENAME, ios::out | ios::binary);
        if (!wf)
        {
            cout << "Cannot open file!" << endl;
            return 1;
        }
        save(wf, myHero);
        save(wf, myEnemy);
        save(wf, third);
        wf.close();
        if (!wf.good())
        {
            cout << "Error occurred at writing time!" << endl;
            return 1;
        }
        cout << "All characters saved. \n";
    }
    else if (opt == 2)
    {
        ifstream rf(FILENAME, ios::in | ios::binary);
        if (!rf)
        {
            cout << "Cannot open file!" << endl;
            return 1;
        }
        load(rf, myHero);
        load(rf, myEnemy);
        load(rf, third);

        rf.close();
        if (!rf.good())
        {
            cout << "Error occurred at reading time!" << endl;
            return 1;
        }
        cout << "All characters loaded from file. \n";
    }

    cout << myHero << endl;
    cout << myEnemy << endl;
    cout << third << endl;
}
