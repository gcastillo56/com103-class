/* Filename: assert.cpp
 *
 * This program showcases the use of the assert function.
 * If the condition inside the assert is not met, the
 * program fails and ends execution.
 *
 * En caso de querer ignorar los asserts, activar el
 * macro NDEBUG quitando el comentario de la linea 14.
 *
 * @author: gcastill
 * June 2023
 */
// The below program runs fine because NDEBUG is defined
// # define NDEBUG
#include <assert.h>
#include <iostream>

int main()
{
    int x;
    std::cout << "Dame el número secreto: ";
    std::cin >> x;
    std::cout << "El número introducido es " << x << std::endl;
    assert(x == 5);
    std::cout << "El número ha sido aceptado\n";
    return 0;
}