#include <iostream>
using namespace std;

void barres(int n) 
{
  if (n == 1) cout << '*' << endl;
  else {
    for (int i = n - 1; 0 < i; --i) barres(i);
    
    for (int i = 1; i < n + 1; ++i) {
      for (int j = 0; j < i; ++j) cout << '*';
      cout << endl;
    }
  }
}

int main () 
{
  int n;
  cin >> n;
  barres(n);
}
