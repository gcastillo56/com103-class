/* Filename: accumulator.cpp
 *
 * This program showcases the use of the auto keyword
 * for data type inference as well
 *
 * @author: gcastill
 * June 2023
 */
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
auto accumulate(const vector<T> &col, T init)
{
    auto res = init;
    for (auto elem : col)
    {
        res += elem;
    }
    return res;
}

int main()
{
    vector<int> col = {1, 2, 3, 4, 5};
    vector<double> cold = {1.3, 2.6, 3.4, 4.1, 5.5};

    cout << typeid(col).name() << " - " << accumulate(col, 0) << endl;
    cout << typeid(cold).name() << " - " << accumulate(cold, 0.0) << endl;
}