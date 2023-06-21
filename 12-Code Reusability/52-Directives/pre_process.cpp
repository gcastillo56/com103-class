/* Filename: pre_process.cpp
 *
 * This program showcases the definition and usage of preprocessor directives.
 *
 * @author: gcastill
 * August 2023
 */
#include <iostream>
using namespace std;
// If I comment or remove this definition, the behavior of the
// program will be modified. Check it out!
#define DEBUG

#define MIN(a, b) (((a) < (b)) ? a : b)

#define MKSTR(x) #x

int main()
{
    int i, j;

    i = 100;
    j = 30;

#ifdef DEBUG
    cerr << "Trace: Inside main function" << endl;
#endif

#if 0
   /* This is commented part */
   cout << MKSTR(HELLO C++) << endl;
#endif

    cout << "The minimum is " << MIN(i, j) << endl;

#ifdef DEBUG
    cerr << "Trace: Coming out of main function" << endl;
#endif

#ifndef DEBUG
    cerr << "Trace: When the DEBUG macro is not defined" << endl;
#endif

    return 0;
}