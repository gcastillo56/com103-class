/* Filename: swap.cpp
 *
 * This program illustrates how to use a template method.
 * The template method will encapsulate a behaviour that could be needed
 * for multiple types.
 *
 * @author: gcastill
 * August 2013
 */
#include <iostream>
#include <string>
using namespace std;

template <typename Item>
inline void mySwap(Item & first, Item & second) {
    Item temp = first;
    first = second;
    second = temp;
}

int main() {
    int i1 = 11, i2 = 22;
    double d1 = 33.3, d2 = 44.4;
    string s1 = "Hi", s2 = "Ho";
    
    cout << "Before swap: ints - " << i1 << ", " << i2 << endl;
    mySwap(i1, i2);
    cout << "After swap: ints - " << i1 << ", " << i2 << endl;

    cout << "Before swap: doubles - " << d1 << ", " << d2 << endl;
    mySwap(d1, d2);
    cout << "After swap: doubles - " << d1 << ", " << d2 << endl;

    cout << "Before swap: strings - " << s1 << ", " << s2 << endl;
    mySwap(s1, s2);
    cout << "After swap: strings - " << s1 << ", " << s2 << endl;
    system("pause");
}