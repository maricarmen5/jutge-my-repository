#include <iostream>
#include <stack>
using namespace std;

bool subPila (stack<int> p1, stack<int> p2) {
    bool resp = true;

    if (not p2.empty()) {
        if (p1.empty()) resp = false;
        else {
            if (p1.top() == p2.top()) {
                p1.pop();

                int n = p2.top();

                subPila(p1, p2);

                
            }
        }
    }

    return resp;
}