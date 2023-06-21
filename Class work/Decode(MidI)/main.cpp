#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int code [] = {4,14,19,21,411,501,607,826,1713,1803,2309,2318,3205,4317,4710,53416,54102,
				55124,88215,112312,122222,569008,793323,814006,932025,988420};

int ARRAY_SIZE = 26;

void merge(int array[], int start, int mid, int end){
	int cnt1 = start;
	int cnt2 = mid;
	int tmp_idx = 0;
	auto const int toMerge = end - start;
	int tmp_array[toMerge];
	do {
		if((array[cnt1]%100) > (array[cnt2]%100)) {
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

void mergesort(int array[], int start, int end) {
	if(end - start <=1){
		return;
	}
	int mid = ((end - start)/2)+start;
	//printArray(array, start, mid,"Parte inicial del arreglo: ");
	//printArray(array, mid, end, "Parte final del arreglo: ");

	mergesort(array, start, mid);
	mergesort(array, mid, end);
	merge(array, start, mid, end);
}

char getCodeFromOrderedArray(int code[], int value){
	for(int i=0; i<ARRAY_SIZE; i++){
		if(code[i]==value){
			return char(i+97);
		}
	}
	return ' ';
}

int main(int argc, char** argv) {
	int aux_array [ARRAY_SIZE];
	int verify[] = {3205,19,988420,88215,3205,19,1803,88215,2318,2318,3205,1803,988420,88215};
	int challenge[] = {21,14,501,14,2309,112312,112312,88215,53416,501,2318,501,607,88215,
	54102,3205,2318,14,501,2318,112312,88215,19,501,988420,88215,4,88215,19,21,14,501,14,2309,
	112312,112312,88215,53416,501,2318,501,3205,14,1803,88215,14,988420,2318,501,2318,112312,
	88215,19,21,14,501,14,2309,112312,112312,88215,53416,501,2318,501,501,988420,2318,501,
	3205,2318,112312,88215,19,501,988420,88215,4,88215,19,932025,501,988420,501,2318,112312,
	88215,19,3205,14,112312,501,19,988420,2309,14,2309,3205,54102,112312,501,19};
	int challenge_size = sizeof(challenge)/sizeof(int);
	for(int i=0; i < ARRAY_SIZE; i++){
		std::cout << i << " - " << code[i]% 100 << std::endl;
	}
	mergesort(code, 0, ARRAY_SIZE);
	std::cout << "----------------------------\n";
	for(int i=0; i < ARRAY_SIZE; i++){
		std::cout << i << " - " << char(96 + (code[i]%100)) << " "  << code[i] << std::endl;
	}
	for(int i=0 ; i<14; i++ ){
		std::cout << getCode(code, verify[i]);
	}
	std::cout << std::endl;
	for(int i=0 ; i<challenge_size; i++ ){
		std::cout << getCode(code, challenge[i]);
	}
	std::cout << std::endl;
	
}
