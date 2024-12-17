#include <iostream>
using namespace std;

int main () 
{
   int x, y;
   cin >> x >> y;

   int bottom = x;
   int top = y;
   if (y < x) {
      bottom = y;
      top = x;
   }
   
   while (bottom <= top) {
      cout << top << endl;
      --top;
   }
}