#include <iostream>
#include <string>

#include "GradoDelArbol.h"

using namespace std;

int main() {
	int numeroDeArboles;
	cin >> numeroDeArboles;
	cin.ignore();			// Para que solo coja el primer elemento y no se raye todo
	for (int i = 0; i < numeroDeArboles; i++) {
		string arbol;	
		getline(cin, arbol);
		int gradoDelArbol = alturaDelArbol(arbol);
		cout << gradoDelArbol << endl;
	}


	return 0;
}