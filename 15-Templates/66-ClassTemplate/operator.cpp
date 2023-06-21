/* Filename: operator.cpp
 *
 * This program illustrates how to use a template class.
 * The template class will encapsulate a behaviour that could be needed
 * for multiple types.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
using namespace std;

// Templating the class.
template <class T>
class Calculator
{
private:
    T num1, num2;

public:
    Calculator(T, T);

    void displayResult();

    T add();
    T subtract();
    T multiply();
    T divide();
};

int main()
{
    // Create an instance of the class for ints
    Calculator<int> intCalc(2, 1);
    // Create an instance of the class for doubles
    Calculator<float> floatCalc(2.4, 1.2);

    cout << "Int results:" << endl;
    intCalc.displayResult();

    cout << endl
         << "Float results:" << endl;
    floatCalc.displayResult();

    return 0;
}

// Function implementations
template <class T>
Calculator<T>::Calculator(T n1, T n2)
{
    num1 = n1;
    num2 = n2;
}

template <class T>
void Calculator<T>::displayResult()
{
    cout << "Numbers: " << num1 << " and " << num2 << "." << endl;
    cout << num1 << " + " << num2 << " = " << add() << endl;
    cout << num1 << " - " << num2 << " = " << subtract() << endl;
    cout << num1 << " * " << num2 << " = " << multiply() << endl;
    cout << num1 << " / " << num2 << " = " << divide() << endl;
}

template <class T>
T Calculator<T>::add() { return num1 + num2; }

template <class T>
T Calculator<T>::subtract() { return num1 - num2; }

template <class T>
T Calculator<T>::multiply() { return num1 * num2; }

template <class T>
T Calculator<T>::divide() { return num1 / num2; }