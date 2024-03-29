#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector <string> v(10);
        
        for (unsigned int j = 0; j<10; ++j) cin>>v[j];
        bool trobat = false;
        int j=1;
        while ((j<10)and(not trobat)) {
            string s=v[j];
            string t=v[j-1];
            if (s[0]!=t[t.size()-1]) {
                trobat=true;
                if (j%2==0) cout<<'B';
                else cout<<'A';
            } 
            else ++j;
        }
        if (not trobat) cout<<'=';
        cout<<endl;
    }
}
