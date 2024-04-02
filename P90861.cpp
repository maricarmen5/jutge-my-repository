#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

void print_queue(queue<string> q, int x)
{
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        if (x == 0) cout << ' ';
        else cout << endl;

        cout << q.front();

        q.pop();
    }
}

int main ()
{
    int n;
    cin >> n;
    cin.ignore();

    string customer;
    vector< queue<string> > v(n);
    for (int i = 0; i < n; ++i) {
        string line;
        if (getline(cin, line)) {
            istringstream ss(line);
            while (ss >> customer) v[i].push(customer);
        }
    }
    cin.ignore();

    
    queue<string> departs;
    string event;
    while (cin >> event) {
        int q;
        if (event == "ENTERS") {
            cin >> customer >> q;
            --q;
            if (0 <= q and q < n) v[q].push(customer);
        } 
        else {
            cin >> q;
            --q;
            if (0 <= q and q < n and not v[q].empty()) {
                departs.push(v[q].front());
                v[q].pop();
            } 
        }
    }

    cout << "DEPARTS" << endl;
    cout << "-------";
    print_queue(departs, 1);
    cout << endl << endl;

    cout << "FINAL CONTENTS" << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "queue " << i + 1 << ':';
        print_queue(v[i], 0);
        cout << endl;
    }
}