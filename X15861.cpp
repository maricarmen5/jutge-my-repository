#include <iostream>
#include <queue>
using namespace std;

// Pre:
// Post: La cua retornada té els mateixos elements que el valor rebut via el
//       paràmetre q, excepte que tot 0 que inicialment tenia un nombre parell
//       d'elements abans que ell ha estat esborrat, i tot 1 que inicialmente
//       tenia un nombre senar d'elements abans que ell ha estat esborrat.
queue<int> remove01(queue<int> q)
{
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        int x = q.front();

        if (x == 0 and i%2 != 0) q.push(x);
        else if (x == 1 and i%2 == 0) q.push(x);
        else if (x != 0 and x!= 1) q.push(x);

        q.pop();
    }

    return q;
}