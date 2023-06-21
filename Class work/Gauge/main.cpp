#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <cmath>
// #define KEYWORD_SIZE 4
using namespace std;

enum Safety { safe = 20, warning = 40, danger = 50, inminent=80, kboom=100, dead };

const int KEYWORD_SIZE = 4;


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
		default: return "Mejor suerte en tu proxima vida.";
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

/*
Método que obtiene la distancia entre un caracter y otro
Params:
 	+ char key - El valor del caracter en la palabra clave.
 	+ char challenge - El valor del caracter en la palabra a verificar
Return:
	+ int - Regresa la diferencia entre key y challenge.

*/
int compareChars(char key, char challenge) {
	int tmp = abs((int)(key - challenge));
	cout << "La diferencia obtenida entre la letra correspondiente y " << challenge
	 	<< " es: " << tmp << endl;
	return tmp;
}


int main(int argc, char** argv) {
	string keyword = "brow";
	string in_str;
	bool eow = false;
	int success;
	int count[KEYWORD_SIZE] = {0,0,0,0};  // Medidor que no tiene que pasar de 100
	int tmp;
	//srand(time(NULL));
	/*for(int i=0; i< KEYWORD_SIZE; i++) {
		count[i]=0;
	}*/
	do {
		 //tmp = rand() % 100;
		 cout << "Introduce la palabra clave (max. 4): ";
		 getline(cin, in_str); // cin >> in_str
		 cout << in_str << endl;
		 success = 0;
		 for(int i=0; i<KEYWORD_SIZE; i++){ // Ciclo para actualizar los contadores
		 	tmp = compareChars(keyword.at(i), in_str.at(i));
		 	count[i] += tmp;
		 	if(tmp == 0) {
		 		success ++;
			 }
		 	
		 }
		 for(int i=0; i<KEYWORD_SIZE; i++){ // Ciclo para verificar si nos hemos pasado
		 	cout << getLabel(validateRange(count[i])) << endl;
		 	if(count[i] >=100) {
		 		eow = true;
			 }
		 }	 
		 cout << success << endl;
		 cout << eow << endl;
	} while(!eow && success < KEYWORD_SIZE);
	if(eow)
		cout << "El mundo se acabo.\nGracias por participar.\nNos vemos en el proximo multiverso.";
	else
		cout << "Felicidades haz salvado al mundo\n";
	
	
	return 0;
}






