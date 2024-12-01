#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename Elem, typename Prio>
class CuaPrio {
public:
  // Constructora, crea una cua buida.                                    
  CuaPrio();

  // Tres grans.
  CuaPrio(const CuaPrio &p);
  CuaPrio& operator=(const CuaPrio &p);
  ~CuaPrio() throw();

  // Afegeix l'element x amb prioritat p a la cua de prioritat.
  void insereix(const Elem &x, const Prio &p);

  // Retorna un element de mínima prioritat en la cua de prioritat. Llança un error si la cua és buida.
  Elem min() const;

  // Retorna la mínima prioritat present en la cua de prioritat. Llança un error si la cua és buida. 
  Prio prio_min() const;

  // Elimina un element de mínima prioritat de la cua de prioritat. Llança un error si la cua és buida.
  void elim_min();

  // Retorna cert si i només si la cua és buida.
  bool es_buida() const throw();

  static const int CuaPrioBuida = 320;

private:

  nat _nelems;                  // Nombre d'elements en el heap.  
  vector<pair<Elem, Prio> > _h; // Vector de pair d'Elem i Prio. La component 0 no s'usa.

  void enfonsar (nat p) throw();
  void surar (nat p) throw();
};

template <typename Elem, typename Prio>
CuaPrio<Elem, Prio>::CuaPrio() : _nelems(0) {
  Elem x;
  Prio p;
  _h.push_back(make_pair(x, p));
}

template <typename Elem, typename Prio>
CuaPrio<Elem, Prio>::CuaPrio(const CuaPrio &p) : _nelems(p._nelems), _h(p._h) {
}

template <typename Elem, typename Prio>
CuaPrio<Elem, Prio>& CuaPrio<Elem, Prio>::operator=(const CuaPrio &p) {
  _nelems = p._nelems;
  _h = p._h;
}

template <typename Elem, typename Prio>
CuaPrio<Elem, Prio>::~CuaPrio() throw() {
}
  
template <typename Elem, typename Prio>
void CuaPrio<Elem, Prio>::insereix(const Elem &x, const Prio &p) {
  _h.push_back(make_pair(x, p));
  ++_nelems; 
  surar(_nelems);
}

template <typename Elem, typename Prio>
Elem CuaPrio<Elem, Prio>::min() const {
  if (_nelems == 0) throw CuaPrioBuida;
  return _h[1].first;
}

template <typename Elem, typename Prio>
Prio CuaPrio<Elem, Prio>::prio_min() const {
  if (_nelems == 0) throw CuaPrioBuida;
  return _h[1].second;
}

template <typename Elem, typename Prio>
void CuaPrio<Elem, Prio>::elim_min() {
  if (_nelems == 0) throw CuaPrioBuida;
  swap(_h[1], _h[_nelems]);
  _h.pop_back();
  --_nelems;
  enfonsar(1);
}

template <typename Elem, typename Prio>
bool CuaPrio<Elem, Prio>::es_buida() const throw() {
  return _nelems == 0;
}

// Enfonsa al node j-èssim fins a restablir l’ordre del monticle a _h; els subarbres del node j són heaps.
template <typename Elem, typename Prio>
void CuaPrio<Elem, Prio>::enfonsar(nat j) throw() {
  nat hj;
  // si j no té fill esquerre ja hem acabat
  if (2*j <= _nelems) {
  hj = 2*j;
    if (hj < _nelems and _h[hj].second > _h[hj+1].second) { 
      ++hj;
    }
    // hj apunta al fill de mínima prioritat de j. 
    // Si la prioritat de j és major que la prioritat del 
    // seu fill menor cal intercanviar i seguir enfonsant.
    if (_h[j].second > _h[hj].second) {
      swap(_h[j], _h[hj]);
      enfonsar(hj);
    }
  }
}

// Fa surar el node p-èssim fins a restablir l’ordre del monticle; tots els nodes excepte el p-èssim satisfan la propietat 3.
template <typename Elem, typename Prio>
void CuaPrio<Elem, Prio>::surar(nat p) throw() {
  nat q;
  bool fi = false;
  while (p > 1 and not fi) {
    q = p / 2;
    if (_h[q].second > _h[p].second) {
      swap(_h[p], _h[q]);
      p = q;
    }
  else {
      fi = true;
    }
  }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    CuaPrio<string, int> cues[n];
    for (int i = 0; i < n; ++i) {
        string linia;
        if (getline(cin, linia)) {
            string nom;
            float edat;

            istringstream ss(linia);
            while (ss >> nom >> edat) cues[i].insereix(nom, -edat);
        }
    }
    cin.ignore();

    vector<string> sortides;
    string succes;
    while (cin >> succes) {
        if (succes == "SURT") {
            int cua;
            cin >> cua;

            if (0 < cua and cua < n+1 and (not cues[cua-1].es_buida())) {
                string expulsat = cues[cua-1].min();
                sortides.push_back(expulsat);
                cues[cua-1].elim_min();
            }
        } else { // ENTRA
            string nom;
            float edat;
            int cua;
            cin >> nom >> edat >> cua;

            if (0 < cua and cua < n+1) cues[cua-1].insereix(nom, -edat);
        }
    }

    cout << "SORTIDES" << endl;
    cout << "--------" << endl;
    for (unsigned int i = 0; i < sortides.size(); ++i) {
        cout << sortides[i] << endl;
    }
    cout << endl;

    cout << "CONTINGUTS FINALS" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "cua " << i+1 << ':';
        while (not cues[i].es_buida()) {
            cout << ' ' << cues[i].min();
            cues[i].elim_min();
        }
        cout << endl;
    }
}