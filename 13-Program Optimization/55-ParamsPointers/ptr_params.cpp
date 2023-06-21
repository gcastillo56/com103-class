/* Filename: ptr_params.cpp
 *
 * This program showcases the basics for pointers as parameters.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>

using namespace std;
void test(int *, int *);
int main()
{
    int a = 5, b = 5;
    cout << "Before changing:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // Notice how we pass the address of the variable
    // not just the value. (Pass by reference)
    test(&a, &b);

    cout << "\nAfter changing" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}

// Parameters are received as addresses
void test(int *n1, int *n2)
{
    *n1 = 10; // We store the value in the address of the parameter,
    *n2 = 11; // thus after the end of the function the value remains
}