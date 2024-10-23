#include "conjunt_2enters.hpp"

cj_2enters::cj_2enters() {
    _card = 0;
}

cj_2enters::cj_2enters(const cj_2enters &cj) {
    for (int i = 0; i < cj._card; ++i) _conj[i] = cj._conj[i];
    _card = cj._card;
}

cj_2enters::~cj_2enters() {
    
}

cj_2enters& cj_2enters::operator=(const cj_2enters &cj) {
    if (this != &cj) {
        for (int i = 0; i < cj._card; ++i) _conj[i] = cj._conj[i];
        _card = cj._card;
    }

    return *this;
}

int cj_2enters::cerca_dicotomica(pair<int, int> pe) const {
    int esq = 0;
    int dre = _card - 1;
    bool trobat = false;

    while (esq <= dre and not trobat) {
        int mig = (esq+dre)/2;

        if (_conj[mig] == pe) {
            esq = mig;
            trobat = true;
        }
        else if (_conj[mig] < pe) esq = mig + 1;
        else dre = mig - 1;
    }

    return esq;
}

void cj_2enters::insereix(pair<int, int> pe) {
    if (_card < MAX) {
        int pos = cerca_dicotomica(pe);

        if (_conj[pos] != pe) {
            for (int i = _card; pos < i; --i) _conj[i] = _conj[i - 1];
            _conj[pos] = pe;
            ++_card;
        }
    }
}

void cj_2enters::unir(const cj_2enters& B) {
    *this = *this + B; 
}

void cj_2enters::intersectar(const cj_2enters& B) {
    *this = *this * B; 
}

void cj_2enters::restar(const cj_2enters& B) {
    *this = *this - B; 
}

cj_2enters cj_2enters::operator+(const cj_2enters& B) const {
    cj_2enters unio = cj_2enters();

    int a = 0;
    int b = 0;
    while (a < _card and b < B._card) {
        if (_conj[a] < B._conj[b]) {
            if (unio._card == 0 or unio._conj[unio._card-1] != _conj[a]) {
                unio._conj[unio._card] = _conj[a];
                ++unio._card;
            }
            ++a;
        } 
        else if (_conj[a] > B._conj[b]) {
            if (unio._card == 0 or unio._conj[unio._card-1] != B._conj[b]) {
                unio._conj[unio._card] = B._conj[b];
                ++unio._card;
            }
            ++b;
        } 
        else {
            if (unio._card == 0 or unio._conj[unio._card-1] != _conj[a]) {
                unio._conj[unio._card] = _conj[a];
                ++unio._card;
            }
            ++a;
            ++b;
        }
    }

    while (a < _card) {
        unio._conj[unio._card] = _conj[a];
        ++a;
        ++unio._card;
    }

    while (b < B._card) {
        unio._conj[unio._card] = B._conj[b];
        ++b;
        ++unio._card;
    }

    return unio;
}

cj_2enters cj_2enters::operator*(const cj_2enters& B) const {
    cj_2enters interseccio = cj_2enters();

    int a = 0;
    int b = 0;
    while (a < _card and b < B._card) {
        if (_conj[a] < B._conj[b]) ++a;
        else if (B._conj[b] < _conj[a]) ++b;
        else {
            if (interseccio._card == 0 or 
            interseccio._conj[interseccio._card-1] != _conj[a]) {
                interseccio._conj[interseccio._card] = _conj[a];
                ++interseccio._card;
            }

            ++a;
            ++b;
        }
    }

    return interseccio;
}

cj_2enters cj_2enters::operator-(const cj_2enters& B) const {
    cj_2enters diferencia = cj_2enters();

    int a = 0;
    int b = 0;
    while (a < _card and b < B._card) {
        if (_conj[a] == B._conj[b]) {
            ++a;
            ++b;
        }
        else if (B._conj[b] < _conj[a]) ++b;
        else {
            if (diferencia._card == 0 or 
            diferencia._conj[diferencia._card-1] != _conj[a]) {
                diferencia._conj[diferencia._card] = _conj[a];
                ++diferencia._card;
            }
            ++a;
        }
    }

    while (a < _card) {
        if (diferencia._card == 0 or 
        diferencia._conj[diferencia._card-1] != _conj[a]) {
            diferencia._conj[diferencia._card] = _conj[a];
            ++diferencia._card;
        }

        ++a;
    }

    return diferencia;
}

bool cj_2enters::conte(pair<int, int> pe) const {
    bool trobat = false;

    int pos = cerca_dicotomica(pe);
    if (pos < _card and _conj[pos] == pe) trobat = true;

    return trobat;
}

// Pre: el conjunt té com a mínim un element
pair<int, int> cj_2enters::max() const { 
    return _conj[_card-1];
}

// Pre: el conjunt té com a mínim un element
pair<int, int> cj_2enters::min() const {
    return _conj[0];
}

int cj_2enters::card() const {
    return _card;
}

bool cj_2enters::operator==(const cj_2enters& B) const {
    bool iguals = true;

    if (_card != B._card) iguals = false;

    int i = 0;
    while (iguals and i < _card) {
        if (_conj[i] != B._conj[i]) iguals = false;
        ++i;
    }

    return iguals;
}

bool cj_2enters::operator!=(const cj_2enters& B) const {
    return not (*this == B);
}

void cj_2enters::print(ostream& os) const {
    os << "[";
    
    for (int i = 0; i < _card; ++i) {
        os << _conj[i].first << "," << _conj[i].second;

        if (i != _card-1) os << " ";
    }

    os << "]";
}