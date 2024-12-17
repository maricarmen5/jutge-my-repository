#include <iostream>
using namespace std;

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
