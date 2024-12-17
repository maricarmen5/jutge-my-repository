#include <iostream>
using namespace std;

int main () 
{
  bool trobat = false;
  char a;
  cin >> a;
  while ((not trobat) and a != '.') {
    if (a == 'a') trobat = true;
    cin >> a;
  }

  if (trobat) cout << "yes" << endl;
  else cout << "no" << endl;
}
