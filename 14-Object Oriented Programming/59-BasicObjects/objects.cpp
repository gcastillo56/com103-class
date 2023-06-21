/* Filename: objects.cpp
 *
 * This program showcases the basics for objects, in this example
 * the object only holds attributes.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
#include <string>
using namespace std;

class Car
{                 // The class
public:           // Access specifier
    string brand; // Attribute (string variable)
    string model; // Attribute (string variable)
    int year;     // Attribute (int variable)
};

int main()
{
    Car myCar; // Create an object of MyClass

    // Access attributes and set values
    myCar.year = 1965;
    myCar.brand = "Ford";
    myCar.model = "Mustang";

    Car carObj1;
    carObj1.brand = "BMW";
    carObj1.model = "X5";
    carObj1.year = 1999;

    // Print attribute values
    cout << myCar.year << " - " << myCar.brand << ", " << myCar.model << endl;
    cout << carObj1.year << " - " << carObj1.brand << ", " << carObj1.model << endl;
    return 0;
}