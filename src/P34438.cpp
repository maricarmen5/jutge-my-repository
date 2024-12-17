#include <iostream>
#include <vector>
using namespace std;

struct Provincia {
    string nom;
    string capital;
    int habitants;
    int area;
    double pib;
};

struct Pais {
    string nom;
    string capital;
    vector<Provincia> provs;
};

typedef vector<Pais> Paisos;

int habitants(const Paisos& p, double x) 
{
    int suma = 0;
    for (unsigned int i = 0; i < p.size(); ++i) {
        Pais a = p[i];
        int k = 0;
        int suma1 = 0;
        for (unsigned int j = 0; j < a.provs.size(); ++j) {
            Provincia b = a.provs[j];
            if (b.pib <= x) ++k;
            suma1 += b.habitants;
        }
        if (2 <= k) suma += suma1;
    }
  
    return suma;
}
