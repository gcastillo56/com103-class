/* Filename: factorial.cpp
 *
 * This program will calculate a factorial using a recursion approach.
 *
 * @author: gcastill
 * August 2013
 */
#include <iostream>
using namespace std;

int factorial(int);

int main() {
    int value;
    cout << "De que valor necesitas el factorial: ";
    cin >> value;
    cout << "f(" << value << ") = " << factorial(value) << endl;
    system("pause");
}

int factorial(int value) {
    if(value > 1)
        return value * factorial(value-1);
    return 1;
}
