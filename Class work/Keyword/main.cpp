#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

enum Safety { safe = 20, warning = 40, danger = 50, inminent=80, kboom=100, dead };

/*
Función que regresa la etiqueta de cada elemento de la enumeración
Params:
 	+ Safety item - El valor del que necesito la etiqueta.
Return:
	+ string - La etiqueta a mostrar.
*/
string getLabel(Safety item) {
	switch(item) {
		case safe: return "Seguro"; break;
		case warning: return "Cuidado"; break;
		case danger: return "Peligro"; break;
		case inminent: return "Peligro inminente"; break;
		case kboom: return "Corre!"; break;
		default: return "Mejor suerte en tu próxima vida.";
	}
}

/*
Esta función valida en que rango cae actualmente mi contador.
Params:
 	+ int value - El valor del contador.
Return:
	+ Safety - Regresa el valor del rango donde se encuentra mi contador.
*/
Safety validateRange(int value) {
	if(value < safe) {
		return safe;
	} else if(value < warning) {
		return warning;
	} else if(value < danger) {
		return danger;
	} else if(value < inminent) {
		return inminent;
	} else if(value < kboom){
		return kboom;
	} else {
		return dead;
	}
}



int main(int argc, char** argv) {
	int count = 0;  // Medidor que no tiene que pasar de 100
	int tmp;
	do {
		 tmp = rand() % 100;
		 cout << "El número obtenido es: " << tmp << endl;
		 count += tmp;  // count = count + tmp
		 
	} while(count <=100);
	cout << "El mundo se acabo.\nGracias por participar.\nNos vemos en el próximo multiverso.";
	
	
	return 0;
}





