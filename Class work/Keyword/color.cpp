#include <iostream>
#include <cstdlib>
#include <string>
//using namespace std;

enum Color { red=30, green=12, blue=25 };
enum Safety { safe = 20, warning = 40, danger = 50, inminent=80 };

/*
metodo: nameColor
parametros: 
	- color (Color)
	
descripcion: Este método recibe un elemento de la enumeración color
			 y regresa la etiqueta del color.

*/
std::string nameColor(Color color) {
	switch(color){
		case red: return "red"; break;
		case green: return "green"; break;
		case blue: return "blue"; break;
		default: return "desconocido";
	}
}

int main_c(int argc, char** argv) {
	char in_char;
	int tmp = rand();
	std::string input;
	
	std::cout << tmp;
	
	Color current_color = green;
	std::cout << "El color actual es: " << nameColor(current_color) << std::endl;
	std::cout <<"Que color quieres: ";
	std::cin >> tmp;
	current_color = Color(tmp);
	std::cout << "El color nuevo es: " << nameColor(current_color) << std::endl;

	
	return 0;
}
