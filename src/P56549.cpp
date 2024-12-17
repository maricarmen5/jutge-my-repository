#include <iostream>
using namespace std;

// Retorna n en base b
void canvi_base(int n, const int& b) {
    int resp = n;
    if (b <= n) {
        canvi_base(n/b, b);
        resp = n%b;
    }
  
    cout << resp;
}

int main () 
{
    int n, b;
    while (cin >> n) {
        cin >> b;
        cout << n << " = ";
        canvi_base(n, b);
        cout << endl;
    }
}
