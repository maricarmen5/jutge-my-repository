#include <iostream>
using namespace std;

int main () 
{
  int hola = -1;

  string sequencia;
  cin >> sequencia;
  
  int i = 0;
  bool trobat = false;
  char caracter = sequencia[i];
  while ((not trobat) and caracter != '.') {
    if (caracter == 'h') hola = 0;
    else if ((caracter == 'o' and hola == 0) or (caracter == 'l' and hola == 1) or (caracter == 'a' and hola == 2)) ++hola;
    else hola = -1;

    if (hola == 3) trobat= true;

    ++i;
    caracter = sequencia[i];
  } 

  if (trobat) cout << "hola" << endl;
  else cout << "adeu" << endl;
}
