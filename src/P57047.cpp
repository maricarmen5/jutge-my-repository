#include <iostream>
#include <vector>
using namespace std;

typedef vector < vector<char> > Matriu;

int main () 
{
  int f;
  while (cin >> f) {
    int c;
    cin >> c;
    Matriu M(f, vector<char>(c));
    for (int i = 0; i < f; ++i) {
      for (int j=0; j<c; ++j) cin >> M[i][j];
    }

    int ri, rj;
    cin >> ri >> rj;

    int mon = 0;
    bool trobat = false;

    string ordre;
    cin >> ordre;
    int mida = ordre.size();
    char a;
    int i = 0;
    while (i < mida and (not trobat)) {
      // Inv:el robot ha efectuat i moviments
      if (ordre[i] == 'N') --ri;
      else if (ordre[i] == 'S') ++ri;
      else if (ordre[i] == 'E') ++rj;
      else --rj;

      a = M[ri][rj];
      if (a == 'B') trobat = true;
      else if (a == '.') ++i;
      else {
        int punts = a - '0';
        mon += punts;
        M[ri][rj]= '.';
        ++i;
      }
    }

    cout << mon << endl;
  }
}