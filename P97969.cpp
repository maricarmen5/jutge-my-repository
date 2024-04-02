#include <iostream>
using namespace std;

// Counting a's (1)
// Counting a's (2) P67454
int main () 
{
  int i = 0;
  char a;
  cin >> a;
  while (a != '.') {
   if (a == 'a') ++i;
   cin >> a;
  }
  
  cout << i << endl;
}
