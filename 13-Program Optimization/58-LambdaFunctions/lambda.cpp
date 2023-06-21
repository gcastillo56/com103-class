/* Filename: lambda.cpp
 *
 * This program showcases the basics for lambda functions.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // lambda function that takes two integer
    // parameters and displays their sum
    auto add = [](int a, int b)
    {
        cout << "Sum = " << a + b << endl;
    };

    // call the lambda function
    add(100, 78);

    // lambda function with explicit return type 'double'
    // returns the sum or the average depending on operation
    auto operation = [](int a, int b, string op) -> double
    {
        if (op == "sum")
        {
            return a + b;
        }
        else
        {
            return (a + b) / 2.0;
        }
    };

    int num1 = 1;
    int num2 = 2;

    // find the sum of num1 and num2
    auto sum = operation(num1, num2, "sum");
    cout << "Sum = " << sum << endl;

    // find the average of num1 and num2
    auto avg = operation(num1, num2, "avg");
    cout << "Average = " << avg << endl;

    int initial_sum = 100;

    // capture initial_sum by value
    auto add_to_sum = [initial_sum](int num)
    {
        // here inital_sum = 100 from local scope
        return initial_sum + num;
    };

    int final_sum = add_to_sum(78);
    cout << "100 + 78 = " << final_sum << endl;

    return 0;
}