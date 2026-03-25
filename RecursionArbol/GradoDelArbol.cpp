#include <string>

#include "GradoDelArbol.h"

using namespace std;

int alturaDelArbolREC(string& arbol, int& indice, int elementosRestantesEnFila);
int limpiarBlancos(string arbol, int indice);

int alturaDelArbol(std::string arbol) {
	int indice = 0;					// Inicialización de variables
	int altura_final = 0;
	
	if (arbol.length() != 0) {		// Comrpueba que el árbol siempre tenga por lo menos un elemento
		int elementosRestantesEnFila = 1;
		altura_final = alturaDelArbolREC(arbol, indice, elementosRestantesEnFila);
	}
	return altura_final;
}

int alturaDelArbolREC(string& arbol, int& indice, int elementosRestantesEnFila) {
	if (elementosRestantesEnFila == 0 || indice >= arbol.length()) {
		return 0;								
	}
	else {
		indice = limpiarBlancos(arbol, indice);
		int ramasRestantes = arbol[indice] - '0';
		indice++;
		int alturaLocal = 1 + alturaDelArbolREC(arbol, indice, ramasRestantes);						// Comprueba el primer elemento que se le ha mandado
		int alturaDemasElementos = alturaDelArbolREC(arbol, indice, elementosRestantesEnFila-1);	// Comprueba el siguiente ( luego este sube otra vez al primer
		int alturaFinal;																			// elemento, recursivamente)
		if (alturaLocal > alturaDemasElementos) {
			alturaFinal = alturaLocal;																// Comprueba la mayor altura
		}																							// y la devuelve
		else {
			alturaFinal = alturaDemasElementos;
		}
		return alturaFinal;
	}
}

int limpiarBlancos(string arbol, int indice) {
	while (arbol[indice] == ' ' && indice < arbol.length()) {
		indice++;
	}
	return indice;
}