#include "llista.hpp"

void Llista::inverteix() {
	node* actual = _prim->seg;
	node* nouprim = NULL;
	while (actual != _prim) {
		node* aux = actual->seg;
		if (nouprim == NULL) {
			actual->seg = _prim;
			_prim->ant = actual;
		} 
		else {
			actual->seg = nouprim;
			nouprim->ant = actual;
		}
		actual->ant = _prim;
		_prim->seg = actual;
		nouprim = actual;
		actual = aux;
	}
}
