//Agenda.cpp
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Agenda.h"

//Implementación de la clase
//Constructor de la clase
Agenda::Agenda( string materia) {
	ponMateria(materia);
}
//Función para poner valor a variable
void Agenda::ponMateria ( string nuevaMateria) {
	nombreMateria = nuevaMateria;
}
//Función para obtener materia
string Agenda::obtenMateria() {
	return nombreMateria;
}
//Función para mostrar el mensaje
void Agenda::muestraMensaje() {
	cout << "Bienvenido a TU clase de "	<< obtenMateria() << endl;
} // Fin de la función
// Fin de la implementacion
