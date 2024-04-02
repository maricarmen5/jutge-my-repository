#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct Nen {
    stack<string> p;
    int caramels = 0;
};

void give(Nen& x, Nen& y, int c) 
{
    for (int i = 0; i < c; ++i) {
        if (not y.p.empty()) {
            x.p.push(y.p.top());
            y.p.pop();
        }
        else ++y.caramels;
    }
}

void print_from_top_to_bottom(stack<string>& S) 
{
  int m = S.size();
  
  for (int i = 0; i < m; ++i) {
    cout << ' ';
    cout << S.top();
    S.pop();
  }
  
  cout << endl;
}

int main () 
{
    int n;
    while (cin >> n) {
        vector<Nen> v(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;

            while (s != "FI") {
                v[i].p.push(s);
                cin >> s;
            }
        }

        int x, y, c;
        cin >> x >> y >> c;
        while (x!= 0) {
            --x;
            --y;
            give(v[x], v[y], c);
            
            cin >> x >> y >> c;
        }

        for (int i = 0; i < n; ++i) {
            cout << v[i].caramels;
            print_from_top_to_bottom(v[i].p);
        }
        cout << "----------" << endl;
    }
}