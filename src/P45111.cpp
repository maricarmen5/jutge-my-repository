#include <iostream>
#include <stack>
using namespace std;

void print_from_top_to_bottom(stack<int>& S) 
{
  int size = S.size();

  for (int i = 0; i < size; ++i) {
    cout << S.top();
    if (i != size - 1) cout << ' ';
    S.pop();
  }
  
  cout << endl;
}

int main () 
{
  stack<int> p;

  int n;
  while (cin >> n) {
    while (n != -1) {
      p.push(n);
      cin >> n;
    }

    print_from_top_to_bottom(p);

    int m = p.size();
    for (int i = 0; i < m; ++i) p.pop();
  }
}
