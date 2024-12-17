#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

/* 
   PRE: v és un heap vàlid des de la posició 0 fins a 
   limit-1, excepte possiblement per la posició arrel.
   POST: restaura la propietat del heap des de la posició 
   arrel fins a limit-1.
   COST TEMPORAL: O(log limit), on n és la mida del heap 
   (limit = dreta - esquerra + 1).
*/
void enfonsar(vector<double>& v, int arrel, int limit) {
    int max = arrel; 
    int fesq = 2*arrel+1;
    int fdre = 2*arrel+2;

    if (fesq < limit and v[max] < v[fesq]) max = fesq;
    if (fdre < limit and v[max] < v[fdre]) max = fdre;

    if (max != arrel) {
        swap(v[arrel], v[max]);
        enfonsar(v, max, limit);
    }
}

/* 
   PRE: v té 2 o més elements.
   POST: tots els elements de v estan ordenats en ordre 
   creixent.
   COST TEMPORAL: O(n log n), on n = v.size(), gràcies a
   la construcció del heap (O(n)) i l'extracció repetida 
   (O(log n) per element).
*/
void heapsort(vector<double>& v) {
    int n = v.size();
    for (int i = (n/2)-1; 0 <= i; --i) enfonsar(v, i, n);

    for (int i = n-1; 0 < i; --i) {
        swap(v[0], v[i]);
        enfonsar(v, 0, i);
    }
}

void ordena_per_fusio(vector<double>& v) {
  if (1 < v.size()) heapsort(v);
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