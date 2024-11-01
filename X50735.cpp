#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void ordena(queue<T>& c) {
  if (1 < (int)c.size()) {
    queue<double> a;
    queue<double> b;
    while (not c.empty()) {
      a.push(c.front());
      c.pop();

      if (not c.empty()) {
        b.push(c.front());
        c.pop();
      }
    }

    ordena<double>(a);
    ordena<double>(b);

    while ((not a.empty()) and (not b.empty())) {
      if (a.front() <= b.front()) {
        c.push(a.front());
        a.pop();
      } else {
        c.push(b.front());
        b.pop();
      }
    }

    if (not b.empty()) a = b;
    while (not a.empty()) {
      c.push(a.front());
      a.pop();
    }
  }
}