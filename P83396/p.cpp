#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Client {
    string nom;
    float edat;
};

class CuaOrdenada {
    private:
        struct node {
            Client info;
            node* seg;
        };

        node* _prim;
        int _card;

    public:
        CuaOrdenada() {
            _prim = nullptr;
            _card = 0;
        }

        void insereix(Client c) {
            node* anterior = nullptr;
            node* actual = _prim;

            while (actual != nullptr and c.edat < actual->info.edat) {
                anterior = actual;
                actual = actual->seg;
            }

            node* nou = new node;
            nou->info = c;
            nou->seg = nullptr;
            
            if (anterior == nullptr) _prim = nou;
            else anterior->seg = nou;
            if (actual != nullptr) nou->seg = actual;

            ++_card;
        }

        Client expulsaMajor() {
            Client expulsat = _prim->info;
            
            node* aux = _prim;
            _prim = _prim->seg;
            delete aux;
            --_card;

            return expulsat;
        }

        int card() {
            return _card;
        }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    CuaOrdenada cues[n];
    for (int i = 0; i < n; ++i) {
        string linia;
        if (getline(cin, linia)) {
            Client c;

            istringstream ss(linia);
            while (ss >> c.nom >> c.edat) cues[i].insereix(c);
        }
    }
    cin.ignore();

    vector<Client> sortides;
    string succes;
    while (cin >> succes) {
        if (succes == "SURT") {
            int cua;
            cin >> cua;

            if (0 < cua and cua < n+1 and 0 < cues[cua-1].card()) {
                Client expulsat = cues[cua-1].expulsaMajor();
                sortides.push_back(expulsat);
            }
        } else { // ENTRA
            Client nou;
            int cua;
            cin >> nou.nom >> nou.edat >> cua;

            if (0 < cua and cua < n+1) cues[cua-1].insereix(nou);
        }
    }

    cout << "SORTIDES" << endl;
    cout << "--------" << endl;
    for (unsigned int i = 0; i < sortides.size(); ++i) {
        cout << sortides[i].nom << endl;
    }
    cout << endl;

    cout << "CONTINGUTS FINALS" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "cua " << i+1 << ':';
        while (0 < cues[i].card()) {
            Client expulsat = cues[i].expulsaMajor();
            cout << ' ' << expulsat.nom;
        }
        cout << endl;
    }
}