/* Filename: ptr_struct.cpp
 *
 * This program showcases the basics for pointers for structures.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
using namespace std;

struct Distance
{
    int feet;
    float inch;
};

int main()
{
    Distance *ptr, d;
    // Observe how in order to store the values we will read we HAVE
    // to create a concrete instance of the struct, then we can use
    // the referenced object to store the values.
    ptr = &d;

    cout << "Enter feet: ";
    cin >> (*ptr).feet; // The value is stored in the address of
    cout << "Enter inch: ";
    cin >> (*ptr).inch;

    cout << "Displaying information." << endl;
    cout << "Distance = " << (*ptr).feet << " feet " << (*ptr).inch << " inches";

    return 0;
}