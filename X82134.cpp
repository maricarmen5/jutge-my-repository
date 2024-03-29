#include <iostream>
#include <vector>
using namespace std;

typedef vector < vector<int> > Matriu;

int elements_per_sota_menors(int i, int j, int a, Matriu& M, int n) 
{
   int p = 0;
   for (int k = i + 1; k < n; ++k) {
     if (M[k][j] < a) ++p;
   }
  
   return p;
}

int main () 
{
   int n, m;
   cin >> n >> m;
  
   Matriu M(n, vector<int>(m));
   for (int i = 0; i < n; ++i) {
     for (int j = 0; j < m; ++j) cin >> M[i][j];
   }
    
  Matriu N(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
       for (int j = 0; j < m; ++j) {
           N[i][j] = elements_per_sota_menors(i, j, M[i][j], M, n);
     
           if (j == 0) cout << N[i][0];
           else cout << ' ' << N[i][j];
       }
      
       cout << endl;
    }
}
