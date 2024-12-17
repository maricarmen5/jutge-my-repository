#include <iostream>
using namespace std;

int main ()
{
  int n;
  cin >> n;

  int dimension = 2*n - 1; 
  int space = n - 1;

  int row = 0;
  while (row < dimension) {
    int absolute_space = space;
    if (space < 0) absolute_space = -space;

    int i = 0;
    while (i < absolute_space) {
       cout << ' ';
       ++i;
    }

    int asterisk = dimension - (2*absolute_space);

    i = 0;
    while (i < asterisk) {
       cout << '*';
       ++i;
    }

    --space;
    cout << endl;

    ++row;
  }  
}

