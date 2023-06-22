//Agenda.cpp
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Agenda.h"

//Implementaci�n de la clase
//Constructor de la clase
Agenda::Agenda( string materia) {
	ponMateria(materia);
}
//Funci�n para poner valor a variable
void Agenda::ponMateria ( string nuevaMateria) {
	nombreMateria = nuevaMateria;
}
//Funci�n para obtener materia
string Agenda::obtenMateria() {
	return nombreMateria;
}
//Funci�n para mostrar el mensaje
void Agenda::muestraMensaje() {
	cout << "Bienvenido a TU clase de "	<< obtenMateria() << endl;
} // Fin de la funci�n
// Fin de la implementacion
