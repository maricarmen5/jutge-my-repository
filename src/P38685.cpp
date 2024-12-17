#include <iostream>
#include <vector>
using namespace std;

bool conte_paraula(const string& a, const string& b) 
{
  bool x = false;

  bool trobat = false;
  int m2 = b.length();
  for (int i = 0; i < m2; ++i) {
    if (a[0] == b[i]) {
      int j = 0;
      int m1 = a.length();
      trobat = false;
      while (0 < m1 and (not trobat)) {
        if (a[j] != b[i+j]) trobat = true; 
        else --m1, ++j;
      }

      if (not trobat) x = true;
    }
  }

  return x;
}

int main () 
{
  string a, b;
  while (cin >> a >> b) {
    if (conte_paraula(a, b)) cout << '+' << endl;
    else cout << '-' << endl;
  }
}
