#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void write_stack(stack<string>& p)
{
    if (not p.empty()) {
        string s = p.top();
        p.pop();
        write_stack(p);
        cout << ' ' << s;
    }
}

int main () 
{
    int n;
    cin >> n;
    cin.ignore();

    string title;
    vector< stack<string> > v(n);
    for (int i = 0; i < n; ++i) {
        string line;
        if (getline(cin, line)) {
            istringstream ss(line);
            while (ss >> title) v[i].push(title);
        }
    }
    cin.ignore();

    string request;
    while (cin >> request) {
        int t;
        if (request == "RETURN") {
            cin >> title >> t;
            --t;
            if (0 <= t and t < n) v[t].push(title);
        } 
        else {
            cin >> t;
            --t;
            if (0 <= t and t < n and (not v[t].empty())) v[t].pop();
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "Stack " << i + 1 << ':';
        write_stack(v[i]);
        cout << endl;
    }
}