/* Filename: vectorio.cpp
 *
 * This program fills a vector with a random number and then displays it in
 * rows of 15 values.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	 
#include <iomanip>
#include <stdlib.h>
#include <vector>
using namespace std;

#define MAX_VALS 100;

int main() {
  int elements;
  vector<double> inputVector;

  /* initialize random seed: */
  srand ((unsigned)time(NULL));
  elements = rand() % MAX_VALS;

  for(int i=0; i<elements; i++){
    inputVector.push_back(((double)rand()/(double)RAND_MAX));
  }
  cout << elements << " elements were introduced in the vector\n"
       << setprecision(1) << fixed << showpoint;
  cout << inputVector.size() << endl;
  for(int i=0; i<inputVector.size() ; i++) {
    cout << setw(5) << inputVector[i];
    if((i+1) % 10 == 0) cout << endl;
  }
  cout << endl;
  system("pause");
}