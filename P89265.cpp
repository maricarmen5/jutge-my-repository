#include <iostream>
using namespace std;

int main () 
{
  // 1=(a,b) 2=(c,d)
  // 1 in 2? 2 in 1? 1=2? intersection(1,2)
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (b < c or d < a) cout << "? , []";
  else if (a == c and b == d) cout << "= , [" << a << ',' << b << ']'; 
  else if (c <= a and b <= d) cout << "1, [" << a << ',' << b << ']';
  else if (a <= c and d <= b) cout << "2, [" << c << ',' << d << ']';
  else cout << "? , [" << max(a, c) << ',' << min(b, d) << endl;
}