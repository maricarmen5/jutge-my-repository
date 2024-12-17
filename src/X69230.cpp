#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;


// Pre: Sigui [a1, a2, a3, a4, ... a{n-2}, a{n-1}, an] el valor inicial rebut en el paràmetre s
// Post: s = [a1, a2-a1, a3-a2+a1, a4-a3+a2-a1, ..., an-a{n-1}+a{n-2}-...]
void alternatedSumBelow_aux(stack<int>& s)
{
    if (1 < s.size()) {
        int top = s.top();
        s.pop();

        //Fita: s.size()
        alternatedSumBelow_aux(s);
        // HI: s = [a1, a2-a1, a3-a2+a1, a4-a3+a2-a1, ..., an-a{n-1}+a{n-2}-...-a{size-1}]

        s.push(top - s.top());
    }
}

// Pre: Sigui [a1, a2, a3, a4, ... a{n-2}, a{n-1}, an] el valor inicial rebut en el paràmetre s.
// Post: Retorna la pila [a1, a2-a1, a3-a2+a1, a4-a3+a2-a1, ..., an-a{n-1}+a{n-2}-...]
stack<int> alternatedSumBelow(stack<int> s)
{
    alternatedSumBelow_aux(s);
    return s;
}

int main()  {}
