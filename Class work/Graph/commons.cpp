/*
Programa: Graph
Archivo: commons.cpp

Este archivo contiene la implementación de varias funciones comúnes para los grafos.
v_1: contendrá solamente el manejo de funciones comúnes para manipular un grafo 
	 en una representación matricial.
v_2: Crearemos sobrecarga de funciones para que también puedan usar estas funciones
	 con una representación por objetos del grafo.

autor: gcastillo

*/
#include <iostream>
using namespace std;

#include "defs.h"

// Prototipo para imprimir matriz completa.
void printMatrix(int m_matrix[][MAX_SIZE]);
// Prototipo para imprimir matriz parcial.
void printMatrix(int m_matrix[][MAX_SIZE], int limit_r, int limit_c);

/*
Método: initGraph
Parámetros: *myGraph - Grafo que se va a inicializar (Paso por referencia)

Inicializa el grafo pasado como parametro

Return: void
*/
void initGraph(Graph* myGraph) {
	myGraph->graph_size = 0;
	for(int i=0; i<MAX_SIZE; i++) {
		for(int j=0; j< MAX_SIZE; j++){
			myGraph->graph_matrix[i][j]=0;
		}
	}
}

/*
Método: inputGraph
Parámetros: *myGraph - Grafo que se va a inicializar (Paso por referencia)

Método que se encargará de pedirle al usuario que intorduzca los valores del grafo manualmente

*/
void inputGraph(Graph* myGraph) {
	int size;
	int t_start, t_end;
	do{
		cout << "Dame el tamano del grafo (Min: 2, Max: " << MAX_SIZE << "): ";
		cin >> size;
		// Validación de datos para que no se pase del límite establecido.
		if(size < 2 || size > MAX_SIZE){
			cout << "Dato invalido. Favor de intentar de nuevo \n";
		}
	} while(size < 2 || size > MAX_SIZE);
	myGraph->graph_size = size;
	
	do {	// Ciclo para leer todas las aristas del grafo.
		cout << "Dame el origen y destino de la arista en el grafo separados por espacios (-1 para terminar): ";
		cin >> t_start >> t_end;
		if(t_start == -1) continue;
		t_start--;	t_end--;	// Ajuste para mantener nomenclatura de nodos
		if(t_start < 0 || t_start > myGraph->graph_size) {
			cout << "El nodo de origen está fuera de rango del grafo.\n";
		} else if(t_end < 0 || t_end > myGraph->graph_size) {
			cout << "El nodo de destino está fuera de rango del grafo.\n";
		} else {
			myGraph->graph_matrix[t_start][t_end] = 1;
			myGraph->graph_matrix[t_end][t_start] = 1;
		}
	} while(t_start != -1);
}

/*
Método: setGraph
Parámetros: 
	- *myGraph - Grafo que se va a inicializar (Paso por referencia)
	- m_matrix - Matriz que contiene el grafo de prueba
	- size - El número de vertices del grafo.

Método que se encargará de copiar la matriz del código en nuestro grafo.

*/
void setGraph(Graph* myGraph, int m_matrix[][MAX_SIZE], int size) {
	myGraph->graph_size = size;
	for(int i=0; i<MAX_SIZE; i++) {
		for(int j=0; j< MAX_SIZE; j++){
			myGraph->graph_matrix[i][j]=m_matrix[i][j];
		}
	}
}

/*
Método: printGraph
Parámetros: myGraph - Grafo que se va a imprimir

Imprime el grafo

Return: void
*/
void printGraph(Graph myGraph){
	cout << "---------------\n";
	cout << "# de nodos: " << myGraph.graph_size << endl;
	printMatrix(myGraph.graph_matrix , myGraph.graph_size, myGraph.graph_size);
	cout << "---------------\n\n";
}


/*
Método: printMatrix
Parámetros: m_matrix - Matriz que se va a imprimir

Imprime una matriz

Return: void
*/
void printMatrix(int m_matrix[][MAX_SIZE]){
	printMatrix(m_matrix, MAX_SIZE, MAX_SIZE);
	cout << "---------------------\n";
}

/*
Método: printMatrix
Parámetros: 
	- m_matrix - Matriz que se va a imprimir
	- limit_r - Limite de los renglones a imprimir
	- limit_c - limite de las columnas a imprimir

Imprime una matriz

Return: void
*/
void printMatrix(int m_matrix[][MAX_SIZE], int limit_r, int limit_c){
	int cnt = 0;
	cout << "     "; 		// Espacio para las columnas (5 caracteres)
	for(int i=0; i<limit_c; i++) {
		cout << i+1 << " ";
		if(i+1 < 10) cout << " ";
		cnt += 3;
	}
	cout << endl;
	cout << "    +";
	for(int i=0; i<cnt; i++) {
		cout << "-";
	}
	cout << endl;
	for(int i=0; i<limit_r; i++) {	// Indice que controla los renglones
		cout << " " << i+1 << " ";
		if(i+1 < 10) cout << " ";
		cout << "|";
		for(int j=0; j< limit_c; j++){	// Indice que controla las columnas
			cout << m_matrix[i][j] << " ";
			if(m_matrix[i][j] < 10) cout << " ";
		}
		cout << endl;
	}
}





