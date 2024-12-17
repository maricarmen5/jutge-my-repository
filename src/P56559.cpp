#include <iostream>
using namespace std;

int main () 
{
  // 1=(a,b) 2=(c,d)
  // 1 in 2? 2 in 1? 1=2? 
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a == c and b == d) cout << '=' << endl;
  else if ((c <= a and b < d) or (c < a and b <= d)) cout << 1 << endl;
  else if ((a <= c and d < b) or (a < c and d <= b)) cout << 2 << endl;
  else cout << '?' << endl;
}
