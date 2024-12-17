#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename T>
class cua { // Cua no circular en memòria dinàmica
public:
    cua();
    // Construeix una cua buida.

    ~cua();
    // Destrueix el p.i.

    cua(const vector<int> &v);
    // Crea cua amb els elements de v amb el mateix ordre.

    nat longitud() const;
    // Retorna el nombre d’elements del p.i.

    void mostra() const;
    // Mostra el p.i. pel canal estàndard de sortida.

    void elimina_majors_suma_anteriors();
    // Pre: c = C
    // Post: El resultat és C on s’han eliminat els elements que són majors
    // que la suma dels inserits abans que ells en la cua original C.

private:
    struct node {
    T info;
    node* seg;
    };
    node* _pri; // Apunta al primer element de la cua
    node* _ult; // Apunta al darrer element de la cua
    nat _mida;

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic elimina_majors_suma_anteriors i privats addicionals
template <typename T>
void cua<T>::elimina_majors_suma_anteriors() { // cost lineal: theta(n)
    T suma = 0;
    node* actual = _pri;
    _ult = NULL;
    while (actual != NULL) {
        if (suma < actual->info) {
            suma += actual->info;
            node* aux = actual;
            actual = actual->seg;
            delete aux;
            --_mida;
            if (_ult == NULL) _pri = actual;
            else _ult->seg = actual;
        } else {
            suma += actual->info;
            _ult = actual;
            actual = actual->seg;
        }
    }
}