/* Filename: inline.cpp
 *
 * This program showcases how a inline function works.
 *
 * @author: gcastill
 * August 2023
 */

#include <iostream>
using namespace std;

inline int cube(int s) { return s * s * s; }

int main()
{
    int val = rand() % 100;
    cout << "The cube of " << val << " is: " << cube(val) << "\n";
    return 0;
}