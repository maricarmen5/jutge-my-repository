#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

struct Comparador {
  bool operator()(const pair<double, string>& a, const pair<double, string>& b) const {
    return a.first < b.first; // Prioritat més alta per edats més altes
  }
};

void mostra_cua(int i, priority_queue< pair<double, string>, vector<pair<double, string>>, Comparador>& cua) {
    cout << "cua " << i+1 << ':';
    while (not cua.empty()) {
        string expulsat = cua.top().second;
        cua.pop();
        cout << ' ' << expulsat;
    }
    cout << endl;
}

void surt_o_entra(int n, vector<string>& sortides, priority_queue< pair<double, string>, vector<pair<double, string>>, Comparador> cues[]) {
    string succes;
    while (cin >> succes) {
        if (succes == "SURT") {
            int cua;
            cin >> cua;

            if (0 < cua and cua < n+1 and (not cues[cua-1].empty())) {
                string expulsat = cues[cua-1].top().second;
                cues[cua-1].pop();
                sortides.push_back(expulsat);
            }
        } else { // ENTRA
            string nom;
            double edat;
            int cua;
            cin >> nom >> edat >> cua;

            if (0 < cua and cua < n+1) cues[cua-1].push({edat, nom});
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    priority_queue< pair<double, string>, vector<pair<double, string>>, Comparador> cues[n];
    for (int i = 0; i < n; ++i) {
        string linia;
        if (getline(cin, linia)) {
            string nom;
            double edat;

            istringstream ss(linia);
            while (ss >> nom >> edat) cues[i].push({edat, nom});
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
    for (int i = 0; i < n; ++i) mostra_cua(i, cues[i]);
}