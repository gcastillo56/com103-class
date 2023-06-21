#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;



int main(int argc, char** argv) {
	string str_var, tmp;
	int id, grade;
	ifstream myfile;
	myfile.open("input.txt");
	
	if(myfile.is_open()){
		while(!myfile.eof()){
			//myfile >> id >> str_var >> grade;
			//cout << id << " " << str_var << " - " << grade << endl;
			getline(myfile, str_var);
			cout << str_var << endl;
			stringstream sstream(str_var);
			while(getline(sstream, tmp, ',')){
				cout << tmp << endl;
			}
			//sstream >> id >> tmp >> grade;
			//cout << id << " " << tmp << " - " << grade << endl;
		}	
	}
	
	myfile.close();
	return 0;
}