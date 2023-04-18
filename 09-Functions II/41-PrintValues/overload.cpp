/* Filename: overload.cpp
 *
 * This program showcases how a regular overloading of a
 * function works.
 *
 * @author: gcastill
 * August 2023
 */

#include <iostream>
using namespace std;

void printValue(int);
void printValue(char);
void printValue(float);
void printValue(int[], int);

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    printValue(10);
    printValue('@');
    printValue(3.14f);
    printValue(arr, len);

    return 0;
}

void printValue(int A)
{
    cout << "Value of int A : " << A << endl;
}

void printValue(int A[], int len = 0)
{
    cout << "\nValue of array A : \n";
    for (int i = 0; i < len; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void printValue(char A)
{
    cout << "Value of char A : " << A << endl;
}

void printValue(float A)
{
    cout << "Value of float A : " << A << endl;
}