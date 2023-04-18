/**
 * filename: dotProduct.cpp
 *
 * Exercise to try a dot product between 2 vectors.
 *
 * @author: gcastillo, 2014
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    double result;
    vector<double> a;
    vector<double> b;

    a.push_back(1.0);
    a.push_back(2.0);
    a.push_back(3.0);

    b.push_back(5.0);
    b.push_back(6.0);
    b.push_back(7.0);

    result = (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]);

    cout << "a:[" << a[0] << ", " << a[1] << ", " << a[2] << "] . b: ["
         << b[0] << ", " << b[1] << ", " << b[2] << "] = " << result << endl;
    system("pause");
}