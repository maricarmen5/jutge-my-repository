#include "llista.hpp"

void Llista::duplica_parells_elimina_senars() {
	node* actual = _prim;
	_ult = NULL;
	while (actual != NULL) {
		if (actual->info%2 == 0) {
			node* nou = new node;
			nou->info = actual->info;
			nou->seg = actual;
			actual->ant = nou;
			if (_ult == NULL) {
				_prim = nou;
				nou->ant = NULL;
			} else {
				nou->ant = _ult;
				_ult->seg = nou;
			}
			_ult = actual;
			actual = actual->seg;
			++_long;
		} else {
			node* aux = actual;
			actual = actual->seg;
			delete aux;
			if (_ult == NULL) {
				_prim = actual;
				if (_prim != NULL) _prim->ant = NULL;
			} else {
				_ult->seg = actual;
				if (actual != NULL) actual->ant = _ult;
			}
			--_long;
		}
	}
}	
