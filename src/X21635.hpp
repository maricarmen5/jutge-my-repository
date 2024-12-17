#include <cstdlib>
#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename T>
class Abin {
public:
    Abin(): _arrel(NULL) {};
    // Pre: cert
    // Post: el resultat és un arbre sense cap element
    Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
    // Pre: cert
    // Post: el resultat és un arbre amb un element i dos subarbres

    // Les tres grans
    Abin(const Abin<T> &a);
    ~Abin();
    Abin<T>& operator=(const Abin<T>& a);

    // operador << d’escriptura
    template <class U> friend std::ostream& operator<<(std::ostream&, const Abin<U> &a);

    // operador >> de lectura
    template <class U> friend std::istream& operator>>(std::istream&, Abin<U> &a);

    bool compleix_suma_fills() const;
    // Pre: true
    // Post: retorna si compleix la propietat ’Suma dels fills’:
    // Per tot node el seu valor és igual a la suma dels valors
    // dels nodes (arrels) del fill esquerre i del fill dret.

private:
    struct node {
    node* f_esq;
    node* f_dret;
    T info;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);
    static void print_nodes(node* m, ostream &os, string d1);

    // Aquí va l’especificació dels mètodes privats addicionals
    bool compleix_suma_fills_aux(node* a) const;
};


// Aquí va la implementació del mètode compleix_suma_fills i dels privats addicionals
template <typename T>
bool Abin<T>::compleix_suma_fills() const {
    bool compleix = compleix_suma_fills_aux(_arrel);
    return compleix;
}

template <typename T>
bool Abin<T>::compleix_suma_fills_aux(node* a) const {
    bool compleix = true;
    if (a != NULL and (a->f_esq != NULL or a->f_dret != NULL)) {
        int fearrel = 0;
        if (compleix_suma_fills_aux(a->f_esq)) {
            if (a->f_esq != NULL) fearrel = a->f_esq->info;
            if (compleix_suma_fills_aux(a->f_dret)) {
                int fdarrel = 0;
                if (a->f_dret != NULL) fdarrel = a->f_dret->info;
                if (fearrel+fdarrel != a->info) compleix = false;
            }
            else compleix = false;
        }
        else compleix = false;
    }
    return compleix;
}