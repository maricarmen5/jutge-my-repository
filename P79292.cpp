#include <queue>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
using namespace std;

typedef vector< vector< queue<string> > > Matrix;

void print_queue(queue<string> q, bool depart)
{
    while (not q.empty()) {
        if (depart) cout << endl;
        else cout << ' ';
        cout << q.front();
        q.pop();
    }
}

int main ()
{
    map<string, int> graduation;
    graduation["soldier"] = 3; 
    graduation["sergeant"] = 2;
    graduation["captain"] = 1;
    graduation["colonel"] = 0;

    int n;
    cin >> n;
    Matrix all_queues(n, vector< queue<string> >(4));
    cin.ignore();

    string customer, range;
    for (int i = 0; i < n; ++i) {
        string line;
        if (getline(cin, line)) {
            istringstream ss(line);
            while (ss >> customer >> range) {
                all_queues[i][graduation[range]].push(customer);
            }
        }
    }
    cin.ignore();

    queue<string> departs;
    string event;
    while (cin >> event) {
        int queue;

        if (event == "ENTERS") {
            cin >> customer >> range >> queue;
            --queue;
            if (0 <= queue and queue < n) all_queues[queue][graduation[range]].push(customer);
        }
        else {
            cin >> queue;
            --queue;
            if (0 <= queue and queue < n) {
                int i = 0;
                while (i < 4) {
                    if (not all_queues[queue][i].empty()) {
                        departs.push(all_queues[queue][i].front());
                        all_queues[queue][i].pop();
                        i = 4;
                    }
                    ++i;
                }
            }
        }
    }

    cout << "DEPARTS" << endl;
    cout << "-------";
    print_queue(departs, true);
    cout << endl << endl;

    cout << "FINAL CONTENTS" << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "queue " << i + 1 << ':';
        for (int j = 0; j < 4; ++j) {
            print_queue(all_queues[i][j], false);
        }
        cout << endl;
    }
}
