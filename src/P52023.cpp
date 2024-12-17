#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

int string_int(string s) 
{
    int n = 0;

    for (int i = s.length() - 1; 0 <= i; --i) {
        int p = 1;
        for (unsigned int j = 0; j < s.length() - 1 - i; ++j) p *= 10;
        n += (s[i] - 48)*p;
    }

    return n;
}

int main () 
{
    string s;
    while (getline(cin, s)) {
        istringstream ss(s);
        string c;
        stack<int> p;
        while (ss >> c) {
            if (c[0] == '+' or c[0] == '-' or c[0] == '*') {
                int b = p.top();
                p.pop();

                int a = p.top();

                if (c[0] == '+') p.top() = a + b;
                else if (c[0]== '-') p.top() = a - b;
                else p.top() = a*b;
            }
            else p.push(string_int(c));
        }

        cout << p.top() << endl;
    }
}