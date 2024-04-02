#include <iostream>
#include <stack>
using namespace std;

int main () 
{
    string s;
    while (cin >> s) {
        stack<char> p;
        for (unsigned int i = 0; i < s.length(); ++i) {
            // Inv:p té parèntesis que encara no tenen parella
            if (p.size() and p.top() == '(' and s[i] == ')') p.pop();
            else if (p.size() and p.top() == '[' and s[i] == ']') p.pop();
            else p.push(s[i]);
        }

        cout << s << " es ";
        if (p.empty()) cout << "correcta" << endl;
        else cout << "incorrecta" << endl;
    }
}