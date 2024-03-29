#include <iostream>
using namespace std;

void barres(int n) 
{
  if (n == 1) cout << '*' << endl;
  else {
    for (int i = n; 0 < i; --i) {
      for (int j = 0; j < i; ++j) cout << '*';
      cout << endl;
    }
    
    for (int i = 1; i < n; ++i) barres(i);
  }
}

int main () 
{
  int n;
  cin >> n;
  barres(n);
}
