/* Filename: ptr_arrays.cpp
 *
 * This program showcases the use of pointers to manipulate arrays.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
using namespace std;
int main()
{
    int *ip;
    int arr[] = {10, 34, 13, 76, 5, 46};
    ip = arr;
    for (int x = 0; x < 6; x++)
    {
        cout << *ip << endl;
        ip++; // The pointer advances the number of addresses based on the type
    }
    return 0;
}