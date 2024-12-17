#include <iostream>
#include <stack>
using namespace std;

/* 
   Pre: Les piles 'a' i 'b' estan ordenades (en ordre ascendent o descendent segons 'pushMajor').
        La pila 'p' està buida o conté elements no rellevants.
   Post: La pila 'p' conté tots els elements de 'a' i 'b', ordenats segons 'pushMajor'.
   Cost temporal: O(n), on n és el nombre total d'elements de les piles 'a' i 'b'.
*/
template <typename T>
void fusiona(stack<T>& p, stack<T>& a, stack<T>& b, bool pushMajor) {
  while ((not a.empty()) and (not b.empty())) {
    if ((a.top() < b.top() and pushMajor) or 
    (b.top() < a.top() and (not pushMajor))) {
      p.push(b.top());
      b.pop();
    } else {
      p.push(a.top());
      a.pop();
    }
  }

  while (not a.empty()) {
    p.push(a.top());
    a.pop();
  }

  while (not b.empty()) {
    p.push(b.top());
    b.pop();
  }
}

/* 
   Pre: La pila 'p' conté els elements desordenats inicials.
   Post: La pila 'p' conté els mateixos elements ordenats en funció de 'pushMajor' (ascendent o descendent).
   Cost temporal: O(n log n), on n és el nombre d'elements de la pila 'p'.
                  La pila es divideix recursivament (log n nivells) i es fusiona en cada nivell (cost lineal O(n)).
*/
template <typename T>
void mergeSort(stack<T>& p, bool pushMajor) {
  if (1 < (int)p.size()) {
    stack<T> a;
    stack<T> b;

    while (1 < (int)p.size()) {
      a.push(p.top());
      p.pop();

      b.push(p.top());
      p.pop();
    }
    if (not p.empty()) {
      a.push(p.top());
      p.pop();
    }

    mergeSort(a, not pushMajor);
    mergeSort(b, not pushMajor);

    fusiona(p, a, b, pushMajor);
  }
}

/* 
   Pre: La pila 'p' conté elements desordenats.
   Post: La pila 'p' conté els mateixos elements ordenats de manera ascendent.
   Cost temporal: O(n log n), on n és el nombre d'elements de la pila 'p'.
*/
template <typename T>
void ordena(stack<T>& p) {
  mergeSort(p, true);
}

/*
template <typename T>
void mostra(stack<T> p) {
  while (not p.empty()) {
    cout << p.top() << ' ';
    p.pop();
  }
  cout << endl;
}

int main() {
  int n;
  while (cin >> n) {
    stack<double> p;
    for (int i=0; i<n; ++i) {
      double x;
      cin >> x;
      p.push(x);
    }

    ordena<double>(p);

    mostra<double>(p);
  }
  return 0;
}
*/