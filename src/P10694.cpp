#include <iostream>
using namespace std;

void barres(int n) 
{
  if (1 < n) {
    barres(n - 1);
    barres(n - 1);
  }

  for (int i = 0; i < n; ++i) cout << '*';
  cout << endl;
}

int main () 
{
  int n;
  cin >> n;
  barres(n);
}
