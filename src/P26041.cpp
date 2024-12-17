#include <iostream>
using namespace std;

void gira_paraules() 
{
  string s;
  if (cin >> s) {
    gira_paraules();
    cout << s << endl;
  }
}

int main () 
{
  gira_paraules();
}
