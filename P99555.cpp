#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matriu;

int main () {
    int n;
    while (cin>>n) {
        Matriu m(n, vector<int>(n));
        vector<bool> check(n*n,0);
        int i, j;
        int all, d1, d2;
        all=0;
        d1=0;
        d2=0;
        for (i=0; i<n; ++i) {
            for (j=0; j<n; ++j) {
                cin>>m[i][j];
                if (check[m[i][j]-1]==0) ++all;
                if (i==j) d1+=m[i][j];
                if (i+j==n-1) d2+=m[i][j];
                check[m[i][j]-1]=1;
            }
        }
        bool found=true;
        if ((all!=n*n)or(d1!=d2)) found=false;
        int sum=0;
        for (i=0; i<n; ++i) {
            // Sum of elements of column j till raw i
            sum+=m[i][0];
        }
        i=0;
        int prove;
        while ((i<n)and(found)) {
            // the sum of elemets in the previous raws is been the same
            j=0, prove=0;
            while ((j<n)and(found)) {
                // Prove is the sum of elements in raw i till column j
                prove+=m[i][j];
                ++j;
            }
            if (sum!=prove) found=false;
            else ++i;
        }
        j=1;
        while ((j<n)and(found)) {
            // the sum of elemets in the previous columns is been the same
            i=0, prove=0;
            while ((i<n)and(found)) {
                // Prove is the sum of elements in column j till raw i
                prove+=m[i][j];
                ++i;
            }
            if (sum!=prove) found=false;
            else ++j;
        }
        if (d1!=sum) found=false;
        if (found) cout<<"yes";
        else cout<<"no";
        cout<<endl;
    }
}
