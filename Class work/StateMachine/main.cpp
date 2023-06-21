#include <iostream>
#include "SMNode.h"

using namespace std;

int main(int argc, char** argv) {
	int val = 0;
	SMNode node("TGA");
	string input = "TACAGCTAGCTEGCTGACACAGTGCATGACGTACGTGACGTGACTTGAT";
	
	for(int i=0; i<input.size(); i++){
		cout << i << endl;
		node.process(input[i]);
	}
	cout << node.welcome();
	cout << "Se encontraron " << node.getCounter() << " instancias de la cadena.\n";
}