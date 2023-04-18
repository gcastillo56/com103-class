/* Filename: calendar.cpp
 *
 * This program showcases the use of an enum to
 * display the months of the year
 *
 * @author: gcastill
 * August 2023
 */

#include <iostream>
#include <string>
using namespace std;

// Defining enum Month
enum Month
{
    JAN,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

string monthLabel(Month);

int main()
{
    // Traversing the year enum
    for (int i = JAN; i <= DEC; i++)
        cout << i + 1 << " - " << monthLabel(Month(i)) << endl;
    return 0;
}

string monthLabel(Month month)
{
    switch (month)
    {
    case JAN:
        return "January";
    case FEB:
        return "February";
    case MAR:
        return "March";
    case APR:
        return "April";
    case MAY:
        return "May";
    case JUN:
        return "June";
    case JUL:
        return "July";
    case AUG:
        return "August";
    case SEP:
        return "September";
    case OCT:
        return "October";
    case NOV:
        return "November";
    case DEC:
        return "December";
    default:
        return "Unknown";
    }
}