#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main ()
{
    queue<string> q;
    string s;

    while (cin >> s) q.push(s);
    vector<queue <string> > v(26);

    int n = s.size();

    for (int i = n - 1; 0 <= i; --i) {
        while (not q.empty()) {
            s = q.front();
            int x = s[i] - 97;
            v[x].push(s);
            q.pop();
        }

        for (int j = 0; j < 26; ++j) {
            while (not v[j].empty()) {
                q.push(v[j].front());
                v[j].pop();
            } 
        }
    }

    while (not q.empty()) {
        cout << q.front();
        if (q.size() != 1) cout << ' ';
        q.pop();
    }
    cout << endl;
}