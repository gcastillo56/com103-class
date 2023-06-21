/* Programa: Clase 0302

	Primer clase para resolver problemas prácticos
	
	Autor: gcastillo
	Fecha: 02-03-23
	
	Problema 1: Implement an algorithm to determine if a string 
	has all unique characters. What if you can not use additional 
	data structures?
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	string input;
	cout << "Dame la palabra a verificar: ";
	cin >> input;
	
	for(int i=0; i<input.length();i++){
		for(int j=i+1; j<input.length();j++){
			if(input[i] == input[j]){
				cout << input[i] << " Caracter repetido\n";
				return 0;
			}
		}
	}
	cout << "Todos los caracteres son unicos\n";
	
	return 0;
}













