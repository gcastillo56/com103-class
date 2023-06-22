//Agenda.h
#include <string>
using std::string;

//Definición de la clase
class Agenda {
public:
	//Constructor de la clase
	Agenda( string );
	//Función para poner valor a variable
	void ponMateria ( string );
	//Función para obtener materia
	string obtenMateria() ;
	//Función para mostrar el mensaje
	void muestraMensaje();// Fin de la función
private:
	string nombreMateria;
};// Fin de la clase
