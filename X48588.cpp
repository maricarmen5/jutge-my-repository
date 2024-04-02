#include <iostream>
using namespace std;

bool triple3(int n) 
{
    int compt = 0;
    while (n != 0) {
        if (n%10 == 3) ++compt; 
        n /= 10;
    }

    bool es_triple3 = false;
    if (compt == 3) es_triple3 = true;
    return es_triple3;
}

int main () 
{
    int compt = 0;
    int p1 = 0;
    int p2 = 0;
    
    int n;
    cin >> n;
    while (n != 0) {
        if (triple3(n)) {
            ++compt;
            
            if (compt == 1) p1 = n;
            else if (compt == 2) p2 = n;
        }

        cin >> n;
    }

    if (compt == 2) cout << p1 << ' ' << p2 << endl;
    else cout << "Nothing" << endl;
}