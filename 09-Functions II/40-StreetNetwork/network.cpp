/* Filename: network.cpp
 *
 * This program will give us all the possible number of paths in
 * a north eastern bound network of all connected map. Uses recursion
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>
using namespace std;

int numberOfPaths(int, int);

int main()
{
    int stRow, stCol, edRow, edCol;
    cout << "Enter starting coordinates (r,c): ";
    cin >> stRow >> stCol;
    cout << "Enter ending coordinates (r,c): ";
    cin >> edRow >> edCol;
    if (edRow - stRow < 0 || edCol - stCol < 0)
    {
        cout << "This program only calculates north-east bound paths\n";
    }
    else
    {
        cout << "\nThere are " << numberOfPaths(edRow - stRow, edCol - stCol)
             << " paths.\n";
    }
    system("pause");
}

int numberOfPaths(int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
    {
        return 1;
    }
    return numberOfPaths(rows - 1, cols) + numberOfPaths(rows, cols - 1);
}