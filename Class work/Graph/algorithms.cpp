/*
Programa: Graph

Este programa es el inicio para la manipulación de un grafo

autor: gcastillo

*/
#include <iostream>
using namespace std;

#include "defs.h"

#define INFINITE 1000

/*
Método: bfs
Parámetros: myGraph - Grafo que se va a recorrer

Método que se encargará de recorrer nuestro grafo segun se lo solicitemos.

*/
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

  
// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[], int n_vertices)
{
    // Initialize min value
    int min = INFINITE, min_index;
    for (int v = 0; v < n_vertices; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

/*
Método: dijkstra
Parámetros: myGraph - Grafo que se va a recorrer

Método que se encargará de buscar el camino mas corto vs todos los nodos.

*/
void dijkstra(Graph myGraph) {
	auto const int maxPath = myGraph.graph_size;
	// Este arreglo contendrá la distancia mas corta desde la fuente a todos los nodos
    int dist[maxPath]; 
  	// Este arreglo nos indicará si el vertice i está en el camino mas corto
    bool sptSet[maxPath]; 
    int init_node = 0;
  
    // Inicializaremos los arreglos auxiliares.
    for (int i = 0; i < maxPath; i++)
        dist[i] = INFINITE, sptSet[i] = false;
  
  do {
		cout << "Introduce el nodo de inicio: ";
		cin >> init_node;
		if (init_node < 1 || init_node > maxPath) {
			cout << "Dato de entrada invalido. Favor de intentar de nuevo. \n";
		}
	} while(init_node < 1 || init_node > maxPath);
	init_node --;
    // Distance of source vertex from itself is always 0
    dist[init_node] = 0;
  
    // Find shortest path for all vertices
    for (int count = 0; count < maxPath - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet, maxPath);
  
        // Mark the picked vertex as processed
        sptSet[u] = true;
  
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < maxPath; v++)
            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && myGraph.graph_matrix[u][v]
                && dist[u] != INFINITE
                && dist[u] + myGraph.graph_matrix[u][v] < dist[v])
                dist[v] = dist[u] + myGraph.graph_matrix[u][v];
    }
  
    // print the constructed distance array
    cout << "Vertice \t Distancia desde el inicio" << endl;
    for (int i = 0; i < maxPath; i++)
        cout << i+1 << " \t\t\t\t" << dist[i] << endl;
}


