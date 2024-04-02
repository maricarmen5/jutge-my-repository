#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

int main ()
{
    string s;
    while (getline(cin, s)) {
        queue<int> q;
        istringstream ss(s);

        int sum = 0;
        int x;
        while (ss >> x) {
            if (x <= sum) q.push(x);
            sum += x;
        }

        int size = q.size();
        while (0 < size) {
            cout << q.front();
            q.pop();
            --size;

            if (size != 1) cout << ' ';
        }
        cout << endl;
    }
}