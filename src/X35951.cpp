#include <iostream>
#include <queue>
using namespace std;

/* 
QuickSort
Pre: cert.
Post: La cua 'c' conté els mateixos elements ordenats en ordre creixent.
Cost temporal: O(n log n) en el cas mig, on n és el nombre d'elements de la cua.
    Això es deu a l'aplicació recursiva de l'algorisme QuickSort, 
    que divideix la cua en dues subcues a cada nivell de recursivitat.

    En el pitjor cas, quan les divisions són molt desequilibrades, 
    el cost és O(n^2).
*/
template <typename T>
void ordena(queue<T>& c) {
  if (not c.empty()) {
    T pivot = c.front();
    c.pop();

    queue<T> a;
    queue<T> b;
    while (not c.empty()) {
      if (c.front() < pivot) a.push(c.front());
      else b.push(c.front());
      c.pop();
    }

    ordena<T>(a);
    ordena<T>(b);

    while (not a.empty()) {
      c.push(a.front());
      a.pop();
    }
    c.push(pivot);
    while (not b.empty()) {
      c.push(b.front());
      b.pop();
    }
  }
}

/*
template <typename T>
void mostra(queue<T> c) {
  while (not c.empty()) {
    cout << c.front() << ' ';
    c.pop();
  }
  cout << endl;
}

int main() {
  int n;
  while (cin >> n) {
    queue<double> c;
    for (int i=0; i<n; ++i) {
      double x;
      cin >> x;
      c.push(x);
    }

    ordena<double>(c);

    mostra<double>(c);
  }
  return 0;
}
*/