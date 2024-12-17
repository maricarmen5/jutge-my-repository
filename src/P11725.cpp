#include <iostream>
#include <vector>
using namespace std;

bool hi_es(int x, const vector<int>& v) 
{
  bool trobat = false;
  int i=0;
  while (i < v.size() and (not trobat)) {
    if (v[i] == x) trobat = true;
    ++i;
  }
  
  return trobat;
}
