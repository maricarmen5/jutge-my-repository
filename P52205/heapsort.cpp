#include <iomanip>
#include <iostream>
#include <vector>
#include <utility> // per utilitzar swap
using namespace std;

/* 
   PRE: v[i..j] és un vector qualsevol, i <= j.
   POST: retorna la posició final del pivot (k) i reorganitza v de manera que:
         - v[i..k-1] conté elements <= pivot.
         - v[k+1..j] conté elements > pivot.
   COST TEMPORAL: O(n), on n = j - i + 1.
*/
int particio(vector<double>& v, int i, int j) {
    double pivot = v[j];
    int p = i-1;

    for (int index = i; index < j; ++index) {
        if (v[index] <= pivot) {
            ++p;
            swap(v[index], v[p]);
        }
    }
    
    ++p;
    swap(v[p], v[j]);
    return p;
}

/* 
   PRE: v[i..j] és un vector qualsevol, i <= j.
   POST: v[i..j] està ordenat en ordre creixent.
   COST TEMPORAL: O(n^2), on n = j - i + 1, en el pitjor cas (vector inversament ordenat).
                  O(n) en el millor cas (vector gairebé ordenat).
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
    if (i < j) {
        if (j-i+1 <= 20) { // M (llindar) = 20
            ordena_per_insercio(v, i, j);
        } else {
            int k = particio(v, i, j);
            quicksort(v, i, k-1);
            quicksort(v, k+1, j);
        }
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