#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<char> > Matriu;

int main () 
{
    int n;
    cin >> n;

    while (n != 0) 
    {
        Matriu m(n, vector<char>(n, '.'));

        int direccioi[] = {0, -1, 0, 1};
        int direccioj[] = {1, 0, -1, 0};
        
        int posi = n - 1;
        int posj = 0;
        for (int costat = n; 0 < costat; --costat)
        {
            for (int x = 0; x < costat; ++x) {
                m[posi][posj] = 'X';

                posi += direccioi[(n - costat)%4];
                posj += direccioj[(n - costat)%4];
            }
            
            posi += direccioi[(n - costat + 2)%4];
            posj += direccioj[(n - costat + 2)%4];

            posi += direccioi[(n - costat + 1)%4];
            posj += direccioj[(n - costat + 1)%4];
        }

        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) cout << m[i][j];
            cout << endl;
        }

        cout << endl;
        cin >> n;
    }
}
