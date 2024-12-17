#include <iostream>
using namespace std;

int main () 
{
   int seconds;
   cin >> seconds;

   int hours = seconds/3600;
   seconds %= 3600;

   int minutes = seconds/60;
   seconds %= 60;

   cout << hours << ' ' << minutes << ' ' << seconds << endl;
}
