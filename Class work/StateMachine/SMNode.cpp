/*
	file: SMNode.cpp
	
	Este archivo contiene la implementación de las
	interfaces de la clase SMNode.
	
	autor: gcastillo
*/
#include <iostream>
#include <string>
#include "SMNode.h"
using namespace std;

SMNode::SMNode(string s_validation) {
	s_goal = s_validation;
	s_index = 0;
	counter = 0;
}

// Función de ejemplo 
string SMNode::welcome() {
	return "Soy un objeto\n";
}

// Método que procesa un caracter a la vez
void SMNode::process(char value) {
	cout << "Chekcing: " << value << " vs " << s_goal[s_index] << endl;
	if(s_goal[s_index] == value) {
		s_index++;
		cout << "Match: " << value << " - index: " << s_index << endl;
		if(s_index == s_goal.size()){
			counter++;
			s_index =0;
			cout << "Cadena encontrada \n";
		}
	} else {
		s_index =0;
		cout << "No match --  index: " << s_index << endl;
		if(s_goal[s_index] == value) {
			s_index++;
			cout << "Match: " << value << " - index: " << s_index << endl;
		}
	}
}

int SMNode::getCounter() {
	return counter;
}