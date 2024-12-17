#include "conjunt_2enters.hpp"

// Constructora, constructora per còpia, destructora i operador d'assignació

cj_2enters::cj_2enters() {
    _card = 0;
    _prim = NULL;
    _ult = NULL;
}

cj_2enters::cj_2enters(const cj_2enters &cj) {
    _prim = NULL;
    copia_conjunt(cj._prim);
    _card = cj._card;
}

cj_2enters::~cj_2enters() {
    destrueix_conjunt(_prim);
}

cj_2enters& cj_2enters::operator=(const cj_2enters &cj) {
    if (this != &cj) {
        cj_2enters copia(cj);
        node* aux = _prim; 
        _prim = copia._prim;
        copia._prim = aux;
        aux = _ult;
        _ult = copia._ult;
        copia._ult = aux;
        int auxcard = _card;
        _card = copia._card;
        copia._card = auxcard;
    }
    return *this;
}

// Mètodes privats addicionals

void cj_2enters::copia_conjunt(node* actual) {
    _ult = NULL;
    while (actual != NULL)
    {
        node* nou = new node;
        nou->info = actual->info;
        nou->seg = NULL;
        if (_ult == NULL) _prim = nou;
        else _ult->seg = nou;
        _ult = nou;
        actual = actual->seg;
    }
}

void cj_2enters::destrueix_conjunt(node* actual) {
    while (actual != NULL) {
        node* aux = actual;
        actual = actual->seg;
        delete aux;
    }
    _prim = NULL;
    _ult = NULL;
    _card = 0;
}

// La resta de funcions i mètodes públics

void cj_2enters::insereix(pair<int, int> pe) {
    node* anterior = NULL;
    node* actual = _prim;

    while (actual != NULL and actual->info < pe) {
		anterior = actual;
		actual = actual->seg;
	}

    if (actual == NULL or actual->info != pe) {
        node* nou = new node;
		nou->info = pe;
		nou->seg = NULL;
        
        if (anterior == NULL) _prim = nou;
        else anterior->seg = nou;

        if (actual == NULL) _ult = nou;
        else nou->seg = actual;

        ++_card;
    }
}

void cj_2enters::unir(const cj_2enters& B) {
    node* actual = _prim;
    node* anterior = NULL;
    node* actualB = B._prim;

    while (actual != NULL and actualB != NULL) {
        if (actualB->info < actual->info) {
            node* nou = new node;
            nou->info = actualB->info;
            nou->seg = actual;

            if (anterior == NULL) _prim = nou;
            else anterior->seg = nou;

            ++_card;
            anterior = nou;
            actualB = actualB->seg;
        } 
        else if (actual->info < actualB->info) {
            anterior = actual;
            actual = actual->seg;
        }
        else actualB = actualB->seg;
    }

    while (actualB != NULL) {
        node* nou = new node;
        nou->info = actualB->info;
        nou->seg = NULL;

        if (_ult == NULL) _prim = nou;
        else _ult->seg = nou;
        
        ++_card;
        _ult = nou;
        actualB = actualB->seg;
    }
}

void cj_2enters::intersectar(const cj_2enters& B) {
    _card = 0;
    _prim = intersectar_aux(_prim, B._prim);
}

cj_2enters::node* cj_2enters::intersectar_aux(node* actual, node* actualB)
{
    node* interseccio = NULL;
    
    if (actual != NULL and actualB != NULL) {
        if (actual->info == actualB->info) {
            interseccio = actual;
            interseccio->seg = intersectar_aux(actual->seg, actualB->seg);
            ++_card;

            if (interseccio->seg == NULL) _ult = interseccio;
        }
        else if (actual->info < actualB->info) {
            interseccio = intersectar_aux(actual->seg, actualB);
        }
        else interseccio = intersectar_aux(actual, actualB->seg);
    }

    return interseccio;
}

void cj_2enters::restar(const cj_2enters& B) {
    node* actual = _prim;
    node* anterior = NULL;
    node* actualB = B._prim;

    while (actual != NULL and actualB != NULL) {
        if (actual->info == actualB->info) {
            if (actual == _ult) _ult = anterior;

            node* aux = actual;
            actual = actual->seg;
            delete aux;

            if (anterior == NULL) _prim = actual;
            else anterior->seg = actual;
        
            --_card;
        }
        else if (actual->info < actualB->info) {
            anterior = actual;
            actual = actual->seg;
        }
        else actualB = actualB->seg;
    }
}

cj_2enters cj_2enters::operator+(const cj_2enters& B) const {
    cj_2enters unio(*this);
    unio.unir(B);
    return unio;
}

cj_2enters cj_2enters::operator*(const cj_2enters& B) const {
    cj_2enters interseccio(*this);
    interseccio.intersectar(B);
    return interseccio;
}

cj_2enters cj_2enters::operator-(const cj_2enters& B) const {
    cj_2enters resta(*this);
    resta.restar(B);
    return resta;
}

bool cj_2enters::conte(pair<int, int> pe) const {
    bool trobat = false;
    node* actual = _prim;

    while ((not trobat) and actual != NULL and actual->info <= pe) {
		if (actual->info == pe) trobat = true;
		actual = actual->seg;
	}

    return trobat;
}

pair<int, int> cj_2enters::max() const { 
    return _ult->info;
}

pair<int, int> cj_2enters::min() const {
    return _prim->info;
}

int cj_2enters::card() const {
    return _card;
}

bool cj_2enters::operator==(const cj_2enters& B) const {
    bool iguals = true;

    if (this != &B) {
        if (_card == B._card) {
		    node* actual = _prim;
		    node* actualB = B._prim;

		    while (iguals and actual != NULL) {
			    if (actual->info != actualB->info) iguals = false;
                actual = actual->seg;
                actualB = actualB->seg;
		    }
	    }
	    else iguals = false;
    }

    return iguals;
}

bool cj_2enters::operator!=(const cj_2enters& B) const {
    return not (*this == B);
}

void cj_2enters::print(ostream& os) const {
	node* actual = _prim;
    os << "[";

    while (actual != NULL) {
        os << actual->info.first << "," << actual->info.second;
        if (actual->seg != NULL) os << " ";
        actual = actual->seg;
    }

    os << "]";
}