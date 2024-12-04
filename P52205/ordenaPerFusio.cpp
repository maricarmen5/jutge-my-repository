#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

/* 
   PRE: v[esquerra..mig] i v[mig+1..dreta] estan ordenats en ordre creixent.
   POST: v[esquerra..dreta] està ordenat en ordre creixent.
   COST TEMPORAL: O(n), on n = dreta - esquerra + 1.
*/
void fusiona(vector<double>& v, int esquerra, int mig, int dreta) {
    int midaEsq = mig-esquerra+1;
    int midaDreta = dreta-mig;

    vector<double> esquerraV(midaEsq);
    for (int i = 0; i < midaEsq; ++i) esquerraV[i] = v[esquerra+i];

    vector<double> dretaV(midaDreta);
    for (int i = 0; i < midaDreta; ++i) dretaV[i] = v[mig+1+i];

    int i = 0;
    int j = 0;
    int k = esquerra;
    while (i < midaEsq and j < midaDreta) {
        if (esquerraV[i] <= dretaV[j]) {
            v[k] = esquerraV[i];
            ++i;
        } else {
            v[k] = dretaV[j];
            ++j;
        }
        ++k;
    }

    while (i < midaEsq) {
        v[k] = esquerraV[i];
        ++i;
        ++k;
    }
    while (j < midaDreta) {
        v[k] = dretaV[j];
        ++j;
        ++k;
    }
}

/* 
   PRE: v és un vector qualsevol, 0 <= esquerra <= dreta < v.size().
   POST: v[esquerra..dreta] està ordenat en ordre creixent.
   COST TEMPORAL: O(n log n), on n = dreta - esquerra + 1.
*/
void mergeSort(vector<double>& v, int esquerra, int dreta) {
    if (esquerra < dreta) {
        int mig = esquerra + (dreta-esquerra) / 2;

        mergeSort(v, esquerra, mig);
        mergeSort(v, mig+1, dreta);

        fusiona(v, esquerra, mig, dreta);
    }
}

/* 
   PRE: v és un vector qualsevol.
   POST: tots els elements de v estan ordenats en ordre creixent.
   COST TEMPORAL: O(n log n), on n = v.size().
*/
void ordena_per_fusio(vector<double>& v) {
    if (0 < v.size()) mergeSort(v, 0, v.size()-1);
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