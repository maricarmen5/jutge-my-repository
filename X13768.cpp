#include <iostream>
#include <vector>
using namespace std;

struct Jugador {
    string nom;
    int salari;
    int punts;
};

typedef vector<Jugador> Jugadors;

Jugador llegirJugador() 
{
    Jugador j;
    cin >> j.nom >> j.salari >> j.punts;
    return j;
}

int obtenir_primerJ(Jugadors& v, int p1, int p2, int esq, int dre) 
{
    int resp=-1;
    if (esq<dre) {
        int pos=(esq+dre)/2;
        bool trobat=false;
        if (pos<=0) trobat=true;
        else {
            if (v[pos-1].punts<p1) trobat=true;
            else trobat=false;
        }
        if ((p1<=v[pos].punts)and(trobat)) resp=pos;
        else if (v[pos].punts<p1) {
            resp=obtenir_primerJ(v, p1, p2, pos, dre);
        } else {
            resp=obtenir_primerJ(v, p1, p2, esq, pos);
        }
    }
    return resp;
}

int obtenir_ultimJ(Jugadors& v, int p1, int p2, int esq, int dre) 
{
    int resp=-1;
    if (esq<dre) {
        int pos=(esq+dre)/2;
        int o=v.size()-1;
        bool trobat=false;
        if (o<=pos) trobat=true;
        else {
            if (p2<v[pos+1].punts) trobat=true;
            else trobat=false;
        }
        if ((v[pos].punts<=p2)and(trobat)) resp=pos;
        else if (p2<v[pos].punts) {
            resp=obtenir_ultimJ(v, p1, p2, esq, pos);
        } else {
            resp=obtenir_ultimJ(v, p1, p2, pos, dre);
        }
    }
    return resp;
}

bool pertanyAInterval(const Jugador &jugador, int p1, int p2) 
{
    bool trobat=false;
    if ((p1<=jugador.punts)and(jugador.punts<=p2)) trobat=true;
    return trobat;
}

int main () 
{
    int n;
    cin>>n;
    Jugadors v(n);
    for (int i=0; i<n; ++i) {
        v[i]=llegirJugador();
    }
    int m;
    cin>>m;
    for (int i=0; i<m; ++i) {
        int p1, p2;
        cin>>p1>>p2;
        if ((v[0].punts<=p2)and(p1<=v[n-1].punts)) {
            int primerJ=obtenir_primerJ(v, p1, p2, 0, n);
            int ultimJ=obtenir_ultimJ(v, p1, p2, 0, n);
            if ((primerJ!=-1)and(ultimJ!=-1)) {
                int suma=0;
                for (int j=primerJ; j<=ultimJ; ++j) {
                    suma+=v[j].salari;
                }
                cout<<suma;
                for (int j=primerJ; j<=ultimJ; ++j) {
                    cout<<' '<<v[j].nom;
                }
                cout<<endl;
            } else cout<<0<<endl;
        } else cout<<0<<endl;
    }
}
