#include <iomanip>
#include <iostream>
#include <vector>
#include <utility> // per utilitzar swap
using namespace std;

/* 
PRE: `v` és un vector inicialitzat amb almenys `j + 1` elements, i `i` i `j` són índexs vàlids dins del vector. 
POST: Els elements de `v[i..j]` estan reorganitzats: els menors o iguals al pivot queden a l'esquerra, els majors a la dreta, i el pivot en la seva posició final. 
COST TEMPORAL: O(j - i + 1), lineal respecte a la mida del subvector.
*/
int particio(vector<double>& v, int i, int j) {
    double pivot = v[i];
    int a = i+1;
    int b = j;

    while (a < b+1) {
        while (a < b+1 and v[a] <= pivot) ++a;
        while (a < b+1 and pivot <= v[b]) --b;
        if (a < b+1) swap(v[a], v[b]);
    }

    swap(v[i], v[b]);
    return b;
}

/* 
PRE: `v` és un vector inicialitzat amb almenys `j + 1` elements, i `i` i `j` són índexs vàlids dins del vector. 
POST: Els elements de `v[i..j]` estan ordenats en ordre creixent. 
COST TEMPORAL: Cas mitjà O(n log n), pitjor cas O(n²). Per subgrups petits (≤ 20 elements), s'utilitza ordenació per inserció amb cost O(m²), on m és la mida del subgrup.
*/
void ordena_per_insercio(vector<double>& v, int i, int j) {
    for (int m = i+1; m <= j; ++m) {
        double element = v[m];
        int n = m-1;

        while (i <= n and element < v[n]) {
            v[n+1] = v[n];
            --n;
        }
        v[n+1] = element;
    }
}

/* 
   PRE: v[i..j] és un vector qualsevol, i <= j.
   POST: v[i..j] està ordenat en ordre creixent.
   COST TEMPORAL: 
         - O(n log n) en el cas mitjà i millor cas (grau d'aleatorietat).
         - O(n^2) en el pitjor cas (vector ja ordenat o inversament ordenat sense optimitzacions).
         - La complexitat es redueix gràcies a l'ús d'ordenació per inserció per a segments petits.
*/
void quicksort(vector<double>& v, int i, int j) {
    if (j-i+1 <= 20) { // M (llindar) = 20
        ordena_per_insercio(v, i, j);
    } else {
        int k = particio(v, i, j);
        quicksort(v, i, k-1);
        quicksort(v, k+1, j);
    }
}

/* 
   PRE: v és un vector qualsevol.
   POST: tots els elements de v estan ordenats en ordre creixent.
   COST TEMPORAL: 
         - O(n log n) en el cas mitjà i millor cas (grau d'aleatorietat).
         - O(n^2) en el pitjor cas (vector ja ordenat o inversament ordenat sense optimitzacions).
*/
void ordena_per_fusio(vector<double>& v) {
    if (0 < v.size()) quicksort(v, 0, v.size()-1);
}

/*int main()
{
    cout << fixed << setprecision(1);
    int n;
    while (cin >> n) {
        vector<double> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        ordena_per_fusio(v);
        for (int i = 0; i < n; ++i) {
            cout << " " << v[i];
        }
        cout << endl;
    }
    return 0;
}*/