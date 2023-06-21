/* Filename: basics.cpp
 *
 * This program showcases the basics for pointers.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
using namespace std;
int main()
{
    int x = 27;
    int *ip;
    ip = &x; // The address of x
    cout << "Value of x is : ";
    cout << x << endl;
    cout << "Value of ip is : ";
    cout << ip << endl;
    cout << "Value of *ip is : ";
    cout << *ip << endl; // The content of the pointer
    // The NULL pointer is a special value
    ip = NULL;
    cout << "Value of ip is: " << ip;
    return 0;
}