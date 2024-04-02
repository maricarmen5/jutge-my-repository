#include <iostream>
#include <stack>
using namespace std;

void uniq_aux(stack<int>& s, int size)
{
    if (1 < size) {
        int top = s.top();
        s.pop();

        uniq_aux(s, size - 1);

        if (top != s.top()) s.push(top);
    } 
}

stack<int> uniq(stack<int> s)
{
    uniq_aux(s, s.size());
    return s;
}

int main() {}