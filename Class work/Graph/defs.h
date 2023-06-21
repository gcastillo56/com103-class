const int MAX_SIZE = 10;

/*
Struct : Graph

- graph_size: Tamaño del grafo(# de nodos)
- graph_matrix: Representación del grafo en formato de matriz.

Objeto principal del programa.
*/
struct Graph {
	int graph_size;
	int graph_matrix[MAX_SIZE][MAX_SIZE] = {
			{0,1,1,0,0, 0,0,0,0,0},
			{1,0,0,0,0, 0,0,0,0,0},
			{1,0,0,0,0, 0,0,0,0,0},
			{0,0,0,0,1, 0,0,0,0,0},
			{0,0,0,1,0, 0,0,0,0,0},
			{0,0,0,0,0, 0,0,0,0,0},
			{0,0,0,0,0, 0,0,0,0,0},
			{0,0,0,0,0, 0,0,0,0,0},
			{0,0,0,0,0, 0,0,0,0,0},
			{0,0,0,0,0, 0,0,0,0,0}
		};
};

void initGraph(Graph* myGraph);