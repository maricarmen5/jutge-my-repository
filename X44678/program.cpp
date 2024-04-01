#include <iostream>
#include <stack>
#include <queue>
#include "Punt.hpp"
#include "stackIOpunt.hpp"
#include "queueIOpunt.hpp"
using namespace std;

void queue_to_stack(queue<Punt>& q, stack<Punt>& s)
{
    if (not q.empty()) {
        Punt p = q.front();
        q.pop();

        queue_to_stack(q, s);

        s.push(p);
    }
}

int main ()
{
    queue<Punt> q;
    while (cin >> q) {
        cout << q;

        stack<Punt> s;
        queue_to_stack(q, s);

        cout << s;
    }
}
