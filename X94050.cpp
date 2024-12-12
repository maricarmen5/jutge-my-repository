#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef unsigned int nat;

/*
  Pre: 'v' és un vector de nombres naturals. 'inici' i 'fi' són índexs vàlids 
       dins del vector (0 <= inici <= fi < v.size()). 'r' és el bit actual a processar.
  Post: El vector 'v' està particionat de manera que els elements amb el bit 'r'
        igual a 0 es troben a l'esquerra i els que tenen el bit 'r' igual a 1, a la dreta.
        Retorna l'índex de l'últim element amb el bit 'r' igual a 0.
  Cost temporal: O(n), on n és el nombre d'elements entre 'inici' i 'fi', 
                 ja que es recorre aquesta secció del vector una sola vegada.
*/
nat particio(vector<nat>& v, int inici, int fi, int r) {
  nat i = inici;
  nat j = fi;

  while (i < j+1) {
    while (i < j+1 and (v[i] & ( 1 << r )) >> r == 0) ++i;
    while (i < j+1 and (v[j] & ( 1 << r )) >> r == 1) --j;
    if (i < j+1) swap(v[i], v[j]);
  }

  return j;
}

/*
  Pre: 'v' és un vector de nombres naturals. 'inici' i 'fi' són índexs vàlids 
       dins del vector (0 <= inici <= fi < v.size()). 'r' és el bit actual a processar.
  Post: Els elements del vector 'v' entre 'inici' i 'fi' estan ordenats segons
        els bits de més pes a menys pes fins al bit 'r'.
  Cost temporal: O(n * log M), on n és el nombre d'elements entre 'inici' i 'fi' 
                 i M és el nombre de bits considerats (M = 2^r). Cada nivell de 
                 recursió processa tots els elements.
*/
void radixSort(vector<nat>& v, int inici, int fi, int r) {
  if (inici < fi and 0 <= r) {
    int k = particio(v, inici, fi, r);
    radixSort(v, inici, k, r-1);
    radixSort(v, k+1, fi, r-1);
  }
}

/*
  Pre: 'v' és un vector de nombres naturals (possiblement buit).
  Post: El vector 'v' està ordenat en ordre creixent.
  Cost temporal: O(n * log M), on n és el nombre d'elements del vector 
                 i M és el nombre de bits màxim a processar (M = 2^r).
                 L'algorisme processa tots els bits de cada element.
*/
void ordena(vector<nat>& v) {
  int num_bits = sizeof(nat) * 8;
  radixSort(v, 0, v.size()-1, num_bits-1);
}

/*
void mostra(vector<nat> v) {
  for (nat i=0; i < v.size(); ++i) {
    cout << v[i] << ' ';
  }
  cout << endl;
}

int main() {
  nat n;
  while (cin >> n) {
    vector<nat> v(n);
    for (nat i=0; i < n; ++i) {
      cin >> v[i];
    }

    ordena(v);

    mostra(v);
  }
  return 0;
}
*/