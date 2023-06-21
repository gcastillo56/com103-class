#include "defs.h"

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