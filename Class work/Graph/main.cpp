/*
Programa: Graph

Este programa es el inicio para la manipulación de un grafo

autor: gcastillo

*/

#include <iostream>
#include "defs.h"
using namespace std;

/*
Método: printGraph
Parámetros: myGraph - Grafo que se va a imprimir

Imprime el grafo

Return: void
*/
void printGraph(Graph myGraph){
	cout << "# de nodos: " << myGraph.graph_size << endl;
	for(int i=0; i < myGraph.graph_size; i++) {
		for(int j=0; j< myGraph.graph_size; j++){
			cout << myGraph.graph_matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------- \n";
}

void bfs(Graph myGraph){
	int init_node = 0;
	int visited[MAX_SIZE];
	int index_visiting = 0;
	int index_2visit = 0;
	// Inicializar el arreglo de visitados
	for(int i= 0; i<MAX_SIZE; i++){
		visited[i] = -1;
	}
	do {
		cout << "Introduce el nodo de inicio: ";
		cin >> init_node;
		if (init_node < 1 || init_node > myGraph.graph_size) {
			cout << "Dato de entrada invalido. Favor de intentar de nuevo. \n";
		}
	} while(init_node < 1 || init_node > myGraph.graph_size);
	visited[index_visiting] = init_node - 1;
	index_2visit ++;
	while(index_visiting != index_2visit){
		for(int i= 0; i<myGraph.graph_size; i++){
			if(myGraph.graph_matrix[visited[index_visiting]][i] == 1) {
				// Existe conexion entre nodo actual y nuevo nodo
				bool exists = false;
				for(int j=0; j<index_2visit; j++){
					if(visited[j] == i){
						exists = true;
						break;
					}
				}
				if(!exists){
					visited[index_2visit] = i;
					index_2visit++;
				}
			}
		}
		index_visiting++;
	}
	cout << "El recorrido en bfs es: ";
	for(int i=0; i<index_2visit; i++) {
		cout << visited[i] + 1 << " ";
	}
	cout << endl;
}

int main(int argc, char** argv) {
	int size;
	int t_start, t_end;
	Graph myGraph;
	//initGraph(&myGraph);
	myGraph.graph_size = 5;
	//myGraph.graph_matrix = t_graph_matrix;
	/*do{
		cout << "Dame el tamano del grafo (Min: 2, Max: " << MAX_SIZE << "): ";
		cin >> size;
		// Validación de datos para que no se pase del límite establecido.
		if(size < 2 || size > MAX_SIZE){
			cout << "Dato invalido. Favor de intentar de nuevo \n";
		}
	} while(size < 2 || size > MAX_SIZE);
	myGraph.graph_size = size;
	
	do {	// Ciclo para leer todas las aristas del grafo.
		cout << "Dame el origen y destino de la arista en el grafo separados por espacios (-1 para terminar): ";
		cin >> t_start >> t_end;
		if(t_start == -1) continue;
		if(t_start < 0 || t_start > myGraph.graph_size) {
			cout << "El nodo de origen está fuera de rango del grafo.\n";
		} else if(t_end < 0 || t_end > myGraph.graph_size) {
			cout << "El nodo de destino está fuera de rango del grafo.\n";
		} else {
			myGraph.graph_matrix[t_start-1][t_end-1] = 1;
			myGraph.graph_matrix[t_end-1][t_start-1] = 1;
		}
	} while(t_start != -1);*/
	printGraph(myGraph);
	bfs(myGraph);
}



