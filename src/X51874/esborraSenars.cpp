#include <iostream>
#include <stack>
using namespace std;

void esborraSenars(stack<int> &p) 
{
    if (not p.empty()) {
        int n = p.top();
        p.pop();

        esborraSenars(p);

        if (n%2 == 0) p.push(n);
    } 
}