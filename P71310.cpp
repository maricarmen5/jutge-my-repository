#include <iostream>
#include <vector>
using namespace std;

double producte_escalar (const vector<double>& u, const vector<double>& v) 
{
    unsigned int i = 0;
    double p = 0;
    while (i < u.size()) {
        // Inv: producte escalar dels subvectors u(0,..,i) i v(0,...,i)
        p += u[i]*v[i];
        ++i;
    }
  
    return p;
}
