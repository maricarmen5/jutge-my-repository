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

double pib(const Paisos& p, char c, double d) 
{
    double suma = 0;
    for (unsigned int i = 0; i < p.size(); ++i) {
        Pais a = p[i];
        if (a.nom[0] == c) {
            for (unsigned int j = 0; j < a.provs.size(); ++j) {
                Provincia b = a.provs[j];
                if (b.area*d < (double)b.habitants) suma += b.pib;
            }
        }
    }
  
    return suma;
}
