#include <string>

#include "GradoDelArbol.h"

using namespace std;

int alturaDelArbolREC(string arbol, int ramas, int altura, int indice);
int limpiarBlancos(string arbol, int indice);

int alturaDelArbol(std::string arbol) {
	int altura = 1;
	int indice = limpiarBlancos(arbol, 0);
	int ramas = arbol[indice] - '0';
	return alturaDelArbolREC(arbol, ramas, altura, indice);
}

int alturaDelArbolREC(string arbol, int ramas, int altura, int indice) {
	indice = limpiarBlancos(arbol, indice);
	int alturaAux = 0;
	if (ramas == 0 || indice >= arbol.length()) {
		return altura;
	}
	else {
		altura++;
		for (int i = 0; i < ramas; i++) {
			indice++;
			alturaAux = alturaDelArbolREC(arbol, arbol[indice+1]-'0', altura, indice);
			if (alturaAux > altura)
				altura = alturaAux;
		}
	}
	return alturaAux;
}

int limpiarBlancos(string arbol, int indice) {
	while (arbol[indice] == ' ' && indice < arbol.length()) {
		indice++;
	}
	return indice;
}