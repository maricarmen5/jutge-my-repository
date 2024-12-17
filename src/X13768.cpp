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

int obte_begin(Jugadors& v, int p, int esq, int dre) 
{
    int index = -1;

    while (esq <= dre) {
        unsigned int pos = (esq + dre)/2;

        if (p <= v[pos].punts) {
            index = pos;
            dre = pos - 1;
        }
        else esq = pos + 1;
    }

    return index;
}

int obte_end(Jugadors& v, int p, int esq, int dre) 
{
    int index = -1;

    while (esq <= dre) {
        int pos = (esq + dre)/2;

        if (v[pos].punts <= p) {
            index = pos;
            esq = pos + 1;
        }
        else dre = pos - 1;
    }

    return index;
}

bool pertanyAInterval(const Jugador &jugador, int p1, int p2) 
{
    bool pertany = false;
    if (p1 <= jugador.punts and jugador.punts <= p2) pertany = true;
    return pertany;
}

int main ()
{
    int n;
    cin >> n;
    Jugadors v(n);
    for (int i = 0; i < n; ++i) v[i] = llegirJugador(); 

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int p1, p2;
        cin >> p1 >> p2;

        int begin = obte_begin(v, p1, 0, n - 1);
        int end = obte_end(v, p2, 0, n - 1);

        if (begin != -1 and end != -1 and begin <= end) {
            int suma_salari = 0;
            for (int j = begin; j <= end; ++j) suma_salari += v[j].salari;
            cout << suma_salari;

            for (int j = begin; j <= end; ++j) cout << ' ' << v[j].nom;
            cout << endl;
        }
        else cout << 0 << endl;
    }
}
