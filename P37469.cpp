#include <iostream>
using namespace std;

int main () 
{
   int seconds;
   cin >> seconds;

   int h, m, s;
   int h = seconds/3600;
   if (h == 0) {
      m = seconds/60;
      if (m == 0) s = seconds; 
      s = seconds%60;
   }
   m = (seconds%3600)/60;
   if (m == 0) s = seconds%3600;
   s = (seconds%3600)%60;

   cout << h << ' ' << m << ' ' << s << endl;
}