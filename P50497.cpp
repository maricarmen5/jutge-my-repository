#include <iostream>
#include <vector>
using namespace std;

bool es_palindrom(const string& s) 
{
 bool trobat = true;

 int size = s.size() - 1;
 int meitat = s.size()/2;
 int i = 0;
 while (trobat and i < meitat) {
  //Inv: el subvector [0..i] i [size...size-i] son inversament iguals.
  if(s[i] != s[size - i]) trobat = false;
  ++i;
 }

 return trobat;
}
