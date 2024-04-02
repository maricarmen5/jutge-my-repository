#include <iostream>
using namespace std;

int main () 
{
  // (a,b) intersection (c,d)
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a <= c) {
    if (c <= b) {
      if (b <= d) cout << '[' << c << ',' << b << ']' << endl;
      else cout << '[' << c << ',' << d << ']' << endl;
    } 
    else cout << "[]" << endl;
  } 
  else {
    if (a <= d) {
      if (d <= b) cout << '[' << a << ',' << d << ']' << endl;
      else cout << '[' << a << ',' << b << ']' << endl;
    } 
    else cout << "[]" << endl;
  } 
}