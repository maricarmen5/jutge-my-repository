#include <iostream>
#include <stack>
using namespace std;

void print_from_top_to_bottom(stack<int>& S) 
{
  int m = S.size();
  
  for (int i = 0; i < m; ++i) {
    cout << S.top();
    if (i != m - 1) cout << ' ';
    S.pop();
  }
  
  cout << endl;
}

void print_from_bottom_to_top(stack<int>& S) 
{
  int m = S.size();
  
  stack<int> p;
  for (int i = 0; i < m; ++i) {
     int n = S.top();
     p.push(n);
     S.pop();
  }
  
  print_from_top_to_bottom(p);
}

