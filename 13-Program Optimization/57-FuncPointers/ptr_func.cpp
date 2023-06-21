/* Filename: ptr_func.cpp
 *
 * This program showcases the basics for pointers for functions.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
using namespace std;

int multiply(int a, int b)
{
    // cout << "Multiplying\n";
    return a * b;
}

// Function containing function pointer
// as parameter
void print(int (*funcptr)(int, int), int a, int b)
{
    cout << "The value of the product is: " << funcptr(a, b)
         << endl;
}

int main()
{
    int (*func)(int, int);

    // func is pointing to the multiply function
    func = multiply;

    int prod = func(15, 2);
    cout << "The value of the product is: " << prod << endl;

    print(multiply, 6, 8);

    return 0;
}