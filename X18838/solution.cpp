#include "llista.hpp"

void Llista::inverteix() {
	node* actual = _prim->seg;
	node* nouprim = NULL;
	while (actual != NULL) {
		node* aux = actual->seg;
		if (nouprim == NULL) actual->seg = NULL;
		else actual->seg = nouprim;
		nouprim = actual;	
		actual = aux;
	}
	_prim->seg = nouprim;
}
