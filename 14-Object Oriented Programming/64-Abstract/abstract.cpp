/* Filename: abstract.cpp
 *
 * This program showcases the use of an abstract class, in this case
 * the parent class Vehicle.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
#include <string>

#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "vehicles.h"
using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    Car myCar(1965, "Ford", "Mustang", 15, 2);
    Car carObj1(1999, "BMW", "X5", 22, 5);

    Bike mybike(2022, "Orbea", "Occam H20");

    myCar.fillTank();
    carObj1.fillTank();

    cout << myCar.report();
    cout << carObj1.report();
    cout << mybike.report();

    int time_to_run = rand() % 100;
    cout << "The test will run for " << time_to_run << " uot. \n";
    // cout << myCar.model << " vs. " << carObj1.model << endl;
    cout << myCar.getModel() << " vs. " << carObj1.getModel()
         << " vs. " << mybike.getModel() << endl;
    for (int i = 0; i < time_to_run; i++)
    {
        cout << i + 1 << " Running ..."
             //<< myCar.miles << " vs. " << carObj1.miles << endl;
             << myCar.getMilage() << " vs. " << carObj1.getMilage()
             << " vs. " << mybike.getMilage() << endl;
        myCar.advance();
        carObj1.advance();
        mybike.advance();
        sleep(1);
    }

    // Print attribute values
    cout << myCar.report();
    cout << carObj1.report();
    cout << mybike.report();
    return 0;
}
