/* Filename: template.cpp
 *
 * This program showcases how a template function simplifies our code.
 *
 * @author: gcastill
 * August 2023
 */

#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

// Special template to capture array variables
template <typename T, size_t N>
void print(const T (&arr)[N])
{
    cout << "Value of " << typeid(arr).name() << ": ";
    for (const auto &x : arr)
        cout << x << " ";
    cout << endl;
}

template <typename T>
void print(const T &a)
{
    cout << "Value of " << typeid(a).name() << ": " << a << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    print(10);
    print('@');
    print(3.14f);
    print(arr);

    return 0;
}