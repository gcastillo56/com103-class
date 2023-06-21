/*
Programa: Matrix

Este programa demuestra la creación y uso de arreglos bidimensionales (matrices)

autor: gcastillo

*/
#include <iostream>
#define MAX_SIZE 3
using namespace std;

/*
Método: printMatrix
Parámetros: m_matrix - Matriz que se va a imprimir

Imprime una matriz

Return: void
*/
void printMatrix(float m_matrix[][MAX_SIZE]){
	for(int i=0; i<MAX_SIZE; i++) {	// Indice que controla los renglones
		for(int j=0; j< MAX_SIZE; j++){	// Indice que controla las columnas
			cout << m_matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------\n";
}

/*
Método: initMatrix
Parámetros: m_matrix - Matriz que se va a inicializar

Inicializa una matriz como matriz identidad

Return: void
*/
void initMatrix(float m_matrix[][MAX_SIZE]) {
	for(int i=0; i<MAX_SIZE; i++) {	// Indice que controla los renglones
		for(int j=0; j< MAX_SIZE; j++){	// Indice que controla las columnas
			m_matrix[i][j] = (i==j) ? 1.0 : 0.0;
		}
	}
}

/*
Método: fillMatrix
Parámetros: m_matrix - Matriz que se va a llenar con la entrada del usuario

Pide al usuario los valores de la matriz

Return: void
*/
void fillMatrix(float m_matrix[][MAX_SIZE]){
	for(int i=0; i<MAX_SIZE; i++) {	// Indice que controla los renglones
		for(int j=0; j< MAX_SIZE; j++){	// Indice que controla las columnas
			cout << "Dame el valor de la matriz en la posicion " << i << "," << j <<": ";
			cin >> m_matrix[i][j];
		}
	}
	printMatrix(m_matrix);
}

void addMatrix(float matrix_a[][MAX_SIZE], float matrix_b[][MAX_SIZE]){
	float matrix_res[MAX_SIZE][MAX_SIZE];	
	for(int i=0; i<MAX_SIZE; i++) {	// Indice que controla los renglones
		for(int j=0; j< MAX_SIZE; j++){	// Indice que controla las columnas
			matrix_res[i][j] = matrix_a[i][j] + matrix_b[i][j];
		}
	}
	printMatrix(matrix_res);
}

void multMatrix(float matrix_a[][MAX_SIZE], float matrix_b[][MAX_SIZE]){
	float matrix_res[MAX_SIZE][MAX_SIZE];	
	for(int i=0; i<MAX_SIZE; i++) {	// Indice que controla los renglones
		for(int j=0; j< MAX_SIZE; j++){	// Indice que controla las columnas
			matrix_res[i][j] = 0;
			for(int k=0; k<MAX_SIZE; k++){
				cout << "i: " << i << "   j: " << j << "  k: " << k;
				matrix_res[i][j] += matrix_a[i][k] * matrix_b[k][j];
				cout << "   Valor de matriz A: " << matrix_a[i][k] << "  Valor de matriz B: " 
					 << matrix_b[k][j] <<"  Resultado actual: " << matrix_res[i][j] << endl;
				system("pause");
			}
		}
	}
	printMatrix(matrix_res);
}


int main(int argc, char** argv) {
	float matrixA[MAX_SIZE][MAX_SIZE];	
	float matrixB[MAX_SIZE][MAX_SIZE];
	initMatrix(matrixA);
	initMatrix(matrixB);	
	fillMatrix(matrixA);
	fillMatrix(matrixB);
	addMatrix(matrixA, matrixB);
	multMatrix(matrixA, matrixB);
}

