//Agenda.h
#include <string>
using std::string;

//Definici�n de la clase
class Agenda {
public:
	//Constructor de la clase
	Agenda( string );
	//Funci�n para poner valor a variable
	void ponMateria ( string );
	//Funci�n para obtener materia
	string obtenMateria() ;
	//Funci�n para mostrar el mensaje
	void muestraMensaje();// Fin de la funci�n
private:
	string nombreMateria;
};// Fin de la clase
