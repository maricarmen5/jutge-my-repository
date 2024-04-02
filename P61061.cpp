#include <iostream>
using namespace std;

int main () 
{
  int n;
  while (cin >> n) {
    if (n < 10) {
        cout << "The product of the digits of " << n;
        cout << " is " << n << '.' << endl;
    }

    while (9 < n) {
      int original = n;

      int product = 1;
      while (0 < n) {
        product *= n%10;
        n /= 10;
      }
      cout << "The product of the digits of " << original;
      cout << " is " << product << '.' << endl;

      n = product;
    }

    cout << "----------" << endl;
  }
}
