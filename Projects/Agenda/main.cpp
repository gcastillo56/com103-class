//LaAgenda.cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include "Agenda.h"

//Funci�n main que iniciar� la ejecuci�n del programa
int main() {
	int pausa;
	string nombreMateria;
	Agenda miAgenda1("Programacion"); // Crear un objeto Agenda
	Agenda miAgenda2("Programacion ++"); // Crear un objeto Agenda
	//cout << "Escribe el nombre de tu materia favorita!" << endl;
	//getline(cin,nombreMateria);
	cout << "La agenda 1 es de la materia " << miAgenda1.obtenMateria() << endl;
	cout << "La agenda 2 es de la materia " << miAgenda2.obtenMateria() << endl;
	//miAgenda.ponMateria(nombreMateria);

	//miAgenda1.muestraMensaje(); // Llama la funci�n que muestra mensaje
	cin >> pausa;
	return 0; // Indica su conclusi�n adecuada
} // fin del main