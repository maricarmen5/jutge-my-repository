#include <iostream>
#include <vector>
using namespace std;

struct Cotxe {
    string nom;
    int distancia;
    int preu;
};

typedef vector<Cotxe> Cotxes;

Cotxe llegirCotxe() 
{
    Cotxe c;
    cin>>c.nom>>c.distancia>>c.preu;
    return c;
}

int obtenir_primerC(Cotxes& v, int p1, int p2, int esq, int dre) 
{
    int resp=-1;
    if (esq<dre) {
        int pos=(esq+dre)/2;
        bool trobat=false;
        if (pos<=0) trobat=true;
        else {
            if (v[pos-1].distancia<p1) trobat=true;
            else trobat=false;
        }
        if ((p1<=v[pos].distancia)and(trobat)) resp=pos;
        else if (v[pos].distancia<p1) {
            resp=obtenir_primerC(v, p1, p2, pos, dre);
        } else {
            resp=obtenir_primerC(v, p1, p2, esq, pos);
        }
    }
    return resp;
}

int obtenir_ultimC(Cotxes& v, int p1, int p2, int esq, int dre) 
{
    int resp=-1;
    if (esq<dre) {
        int pos=(esq+dre)/2;
        int o=v.size()-1;
        bool trobat=false;
        if (o<=pos) trobat=true;
        else {
            if (p2<v[pos+1].distancia) trobat=true;
            else trobat=false;
        }
        if ((v[pos].distancia<=p2)and(trobat)) resp=pos;
        else if (p2<v[pos].distancia) {
            resp=obtenir_ultimC(v, p1, p2, esq, pos);
        } else {
            resp=obtenir_ultimC(v, p1, p2, pos, dre);
        }
    }
    return resp;
}

bool pertanyAInterval(const Cotxe &cotxe, int p1, int p2) 
{
    bool a=false;
    if ((p1<=cotxe.distancia)and(cotxe.distancia<=p2)) a=true;
    return a;
}

int main () 
{
    int n;
    cin>>n;
    Cotxes v(n);
    for (int i=0; i<n; ++i) v[i] = llegirCotxe();
    
    int m;
    cin>>m;
    for (int i=0; i<m; ++i) {
        int p1, p2;
        cin>>p1>>p2;
        if ((v[0].distancia<=p2)and(p1<=v[n-1].distancia)) {
            int primerC=obtenir_primerC(v, p1, p2, 0, n);
            int ultimC=obtenir_ultimC(v, p1, p2, 0, n);
            if ((primerC!=-1)and(ultimC!=-1)) {
                int suma=0;
                for (int j=primerC; j<=ultimC; ++j) {
                    suma+=v[j].preu;
                }
                cout<<suma;
                for (int j=ultimC; primerC<=j; --j) {
                    cout<<' '<<v[j].nom;
                }
                cout<<endl;
            } else cout<<0<<endl;
        } else cout<<0<<endl;
    }
}
