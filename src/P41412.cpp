#include <iostream>
#include <vector>
using namespace std;

// Igual a al problema P98179
void ordena_per_insercio(vector<double>& v) 
{
    for (unsigned int i = 1; i < v.size(); ++i) {
        double x = v[i];
        int j = i;
        while (0 < j and x < v[j-1]) {
            // Inv: v[0..j-1] i v[j+1..i] està ordenat de forma creixent
            v[j] = v[j-1];
            --j;
        }
  
        v[j] = x;
    }
}
