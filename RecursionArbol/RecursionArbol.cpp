#include <iostream>
#include <string>

#include "GradoDelArbol.h"

using namespace std;

int main() {
	int numeroDeArboles;
	cin >> numeroDeArboles;
	for (int i = 0; i < numeroDeArboles; i++) {
		string arbol;
		cin.ignore();
		getline(cin, arbol);
		int gradoDelArbol = alturaDelArbol(arbol);
		cout << gradoDelArbol;
	}


	return 0;
}