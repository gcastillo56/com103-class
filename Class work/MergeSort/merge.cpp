#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int ARRAY_SIZE = 20;		// Tamaño del arreglo

/*
Método para imprimir
*/
void printArray_c(int array[], int init, int end, std::string label) {
	std::cout << label;
	for(int i=init; i<end; i++){
		std::cout<< array[i] << ",";
	}	
	std::cout << std::endl;
}

void merge_c(int array[], int start, int mid, int end){
	int cnt1 = start;
	int cnt2 = mid;
	int tmp_idx = 0;
	auto const int toMerge = end - start;
	int tmp_array[toMerge];
	do {
		if(array[cnt1]>array[cnt2]) {
			tmp_array[tmp_idx++] = array[cnt2++];
		} else {
			tmp_array[tmp_idx++] = array[cnt1++];
		}
	} while(cnt1 < mid && cnt2 < end);
	if(cnt1 < mid){
		do {
			tmp_array[tmp_idx++] = array[cnt1++];
		}while(cnt1 < mid);
	} else {
		do {
			tmp_array[tmp_idx++] = array[cnt2++];
		}while(cnt2 < end);
	}
	//printArray(tmp_array, 0, toMerge, "Tmp array: ");
	tmp_idx =0;
	for(int i=start; i<end;i++) {
		array[i] = tmp_array[tmp_idx++];
	}
}

void mergesort_c(int array[], int start, int end) {
	if(end - start <=1){
		return;
	}
	int mid = ((end - start)/2)+start;
	//printArray(array, start, mid, "Parte inicial del arreglo: ");
	mergesort_c(array, start, mid);
	//printArray(array, mid, end, "Parte final del arreglo: ");
	mergesort_c(array, mid, end);
	merge_c(array, start, mid, end);
	//printArray(array, start, end, "Intermedio fusionado arreglo: ");	
}

int main_c(int argc, char** argv) {
	int array[ARRAY_SIZE];			// Arreglo que contendrá los números a ordenar
	srand(time(NULL));
	// Ciclo para inicializar el arreglo con valores aleatorios
	for(int i=0; i<ARRAY_SIZE; i++){
		array[i] = (rand() %100 )+1;
	}
	printArray_c(array, 0, ARRAY_SIZE, "Arreglo inicial: ");
	mergesort_c(array, 0, ARRAY_SIZE);
	printArray_c(array, 0, ARRAY_SIZE, "Arreglo final: ");
	return 0;
}
