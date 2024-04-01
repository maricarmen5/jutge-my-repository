#include <iostream>
#include <stack>
using namespace std;

void remove01_aux(stack<int>& p)
{
    if (not p.empty()) {
        int n;
        n = p.top();

        p.pop();
        int size = p.size();

        remove01_aux(p);

        if (n == 1) {
            if (size % 2 == 0) p.push(n);
        } 
        else if (n == 0) {
            if (size % 2 != 0) p.push(n);
        }
        else p.push(n);
    }
}

stack<int> remove01(stack<int> s)
{
    remove01_aux(s);
    return s;
}