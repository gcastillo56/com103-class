/*
* 	file: SMNode.h

	Este archivo contiene la definición del nodo
	que usaremos dentro de nuestra máquina de estado
	
	autor: gcastillo
*/

#include <string>
using namespace std;

class SMNode {
	private:
		// Variable que contiene la secuencia a validar
		string s_goal;
		// Indice procesado en cualquier momento.
		int s_index;
		// Contador de secuencias encontradas.
		int counter;
	
	public:
		// Constructor que recibe el string a verificar
		SMNode(string);
		// Función de ejemplo 
		string welcome();
		// Método que procesa un caracter a la vez
		void process(char);
		// Función que regresa el contador al final del proceso.
		int getCounter();
	
};
