/* Filename: access_control.cpp
 *
 * This program showcases the use of exception handling. Observe
 * The different types of exceptions thrown as well as a generic
 * way of catching other unexpected exceptions.
 *
 * @author: gcastill
 * June 2023
 */
#include <iostream>
using namespace std;

enum Access
{
    GRANTED,
    DENIED
};

enum Profile
{
    USER,
    ADMIN
};

int main()
{
    try
    {
        int age, access;
        cout << "Input your age: ";
        cin >> age;
        if (age >= 18)
        {
            cout << "Access granted - you are old enough.\n";
            cout << "What is your range (1-5): ";
            cin >> access;
            if (access < 3)
            {
                throw USER;
            }
            else if (access < 5)
            {
                throw ADMIN;
            }
            throw 404;
        }
        else
        {
            throw DENIED;
        }
    }
    catch (Access myNum)
    {
        cout << "Access denied - You must be at least 18 years old.\n";
        cout << "Error number: " << myNum;
    }
    catch (Profile myProfile)
    {
        if (myProfile == ADMIN)
            cout << "You are admin\n";
        else
            cout << "You are user\n";
    }
    catch (...)
    {
        cout << "Access denied - Your access level is not a valid one.\n";
    }
}