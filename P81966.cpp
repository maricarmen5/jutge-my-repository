#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) 
{
    int resp;
    int pos = (esq+dre)/2;
  
    if (dre < esq) resp = -1;
    else if (x == v[pos]) resp = pos;
    else if (v[pos] < x) resp = posicio(x, v, pos + 1, dre);
    else resp = posicio(x, v, esq, pos - 1);
  
    return resp;
}
