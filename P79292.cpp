#include <queue>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

typedef vector< vector< queue<string> > > Matriu;

int obte_rang(string& graduacio) {
    int rang = 0; // coronel
    if (graduacio == "soldat") rang = 3;
    else if (graduacio == "sergent") rang = 2;
    else if (graduacio == "capita") rang = 1;
    return rang;
}

void surt_o_entra(int n, vector<string>& sortides, Matriu& cues) {
    string succes;
    while (cin >> succes) {
        if (succes == "SURT") {
            int cua;
            cin >> cua;

            if (0 < cua and cua < n+1) {
                int i = 0;
                while (i < 4) {
                    if (not cues[cua-1][i].empty()) {
                        string expulsat = cues[cua-1][i].front();
                        cues[cua-1][i].pop();
                        sortides.push_back(expulsat);
                        i = 4;
                    }
                    ++i;
                }
            }
        } else { // ENTRA
            string nom;
            string graduacio;
            int cua;
            cin >> nom >> graduacio >> cua;

            if (0 < cua and cua < n+1) cues[cua-1][obte_rang(graduacio)].push(nom);
        }
    }
}

void mostra_cua(int n, Matriu& cues) {
    for (int i = 0; i < n; ++i) {
        cout << "cua " << i+1 << ':';
        for (int j = 0; j < 4; ++j) {
            while (not cues[i][j].empty()) {
                string expulsat = cues[i][j].front();
                cues[i][j].pop();
                cout << ' ' << expulsat;
            }
        }
        cout << endl;
    }
}

int main () {
    int n;
    cin >> n;
    cin.ignore();

    Matriu cues(n, vector< queue<string> >(4));

    for (int i = 0; i < n; ++i) {
        string line;
        if (getline(cin, line)) {
            istringstream ss(line);
            string nom, graduacio;
            while (ss >> nom >> graduacio) {
                cues[i][obte_rang(graduacio)].push(nom);
            }
        }
    }
    cin.ignore();

    vector<string> sortides;
    string succes;
    surt_o_entra(n, sortides, cues);

    cout << "SORTIDES" << endl;
    cout << "--------" << endl;
    for (unsigned int i = 0; i < sortides.size(); ++i) {
        cout << sortides[i] << endl;
    }
    cout << endl;

    cout << "CONTINGUTS FINALS" << endl;
    cout << "-----------------" << endl;
    mostra_cua(n, cues);
}