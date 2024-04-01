#include <iostream>
using namespace std;

int main () 
{
  string sequence;
  cin >> sequence;

  bool trobat = false;
  int i = 0;
  while ((not trobat) and sequence[i + 4] != '.') {
    if (sequence[i] == 'h' and sequence[i + 1] == 'e') {
        if (sequence[i + 2] == 'l') {
            if (sequence[i + 3] == 'l') {
              if (sequence[i + 4] == 'o') trobat = true;
              else i += 4;
            }
            else i += 3;
        }
        else i += 2;
    }
    else ++i;
  } 

  if (trobat) cout << "hello" << endl;
  else cout << "bye" << endl;
}