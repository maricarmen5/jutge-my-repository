#include <iostream>
#include <queue>
using namespace std;


// Pre: Rep dues cues d'enters positius q1 i q2.
// Post: Retorna una cua, on al seu front hi ha el màxim 
// dels fronts de q1,q2, després, en segon lloc el màxim 
// dels segons llocs de q1,q2, i així successivament.
// Quan una de les dues cues no té valors definits en 
// alguna posició, la cua resultant hi té el valor de 
// l'altra cua en aquella posició.
queue<int> maximumQueue(queue<int> q1,queue<int> q2) {
    queue<int> r;
    int n;

    while ( (not q1.empty()) and (not q2.empty()) ) {
        // Inv:cap de les dues cues és buida
        n = q1.front();
        if (n < q2.front()) n = q2.front();

        r.push(n);

        q1.pop();
        q2.pop();
    } 

    while (not q1.empty()) {
        r.push(q1.front());
        q1.pop();
    }

    while (not q2.empty()) {
        r.push(q2.front());
        q2.pop();
    }

    return r;
}
