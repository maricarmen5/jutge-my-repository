#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// Pre:  Sigui Q el valor inicial de la cua q que es rep com a paràmetre.
//       Els valors guardats a Q son majors o iguals a 0.
// Post: Sigui Q' la cua retornada. Q i Q' tenen el mateix nombre d'elements.
//       A més a més, per a cada posició p de Q', si Q té un valor x diferent de 0 a posició p,
//       llavors Q' també té x a posició p.
//       En canvi, si Q té valor 0 a posició p, llavors el valor de Q' a posició p és
//       la suma de tots els valors de Q a posició parell abans que p.
queue<int> replace0sWithPreviousSumPosEven(queue<int> q)
{
    int size = q.size();
    int suma = 0;

    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) suma += q.front();

        if (q.front() == 0) q.push(suma);
        else q.push(q.front());

        q.pop();
    }

    return q;
}

int main () {}