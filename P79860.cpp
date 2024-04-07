#include <iostream>
using namespace std;

void barres(int n) 
{
  for (int i = 0; i < n; ++i) cout << '*';
  cout << endl;

  if (1 < n) {
    barres(n - 1);
    barres(n - 1);
  }
}

int main () 
{
  int n;
  cin >> n;
  barres(n);
}
