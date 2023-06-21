#include <iostream>
using namespace std;


double cuadrados(double valor) {
	return valor * valor;
}

int main(int argc, char** argv) {
	int valor=11;
	double valorD = 11.6;
	int valores[10] = {0,1,2,3,4,5,6,7,8,9};
	
	cout << "Hello world\n";
	if(valor == 6){
		cout << "menor a 6\n";
	} else if(valor < 8) {
		cout << "menor a 8\n";
	}  else {
		cout << "otra cosa\n";
	}
	if(valor >0){
		cout << "mayor a 0\n";
	}
	if(valor < 10){
		cout << "menor a 10\n";
	}
	
	for(int i=0; i<valor; i++){
		cout << i << "-" << valores[i]*10 << "-" << cuadrados(valores[i]) << endl;
	}
	
	return 0;
}
