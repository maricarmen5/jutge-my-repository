#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

int main () 
{
    string s;
    while (getline(cin, s)) {
        istringstream ss(s);
        stack<int> p, q;
        int x;
        while (ss >> x) {
            if (x%2 == 0) p.push(x);
            else q.push(x);
        }


        while (not p.empty()) {
            cout << p.top();
            p.pop();
            if ((not p.empty()) or (not q.empty())) cout << ' ';
        }
        while (not q.empty()) {
            cout << q.top();
            q.pop();
            if (not q.empty()) cout << ' ';
        }
        
        cout << endl;
    }
}