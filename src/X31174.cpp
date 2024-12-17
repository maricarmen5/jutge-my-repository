#include <iostream>
#include <stack>
using namespace std;

void remove01_aux(stack<int>& p)
{
    if (not p.empty()) {
        int top = p.top();

        p.pop();
        int size = p.size();

        remove01_aux(p);

        if ((top == 1 and size%2 == 0)
        or (top == 0 and size%2 != 0)
        or (top != 0 and top != 1)) p.push(top);
    }
}

stack<int> remove01(stack<int> s)
{
    remove01_aux(s);
    return s;
}
