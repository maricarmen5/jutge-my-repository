#include <iostream>
#include <queue>
#include "Punt.hpp"
#include "queueIOpunt.hpp"
using namespace std;

void elimina_punts_aux(queue<Punt>& q, Punt p, int size)
{
    if (size != 0) {
        Punt p_aux = q.front();
        q.pop();

        if (not (p == p_aux)) q.push(p_aux);

        elimina_punts_aux(q, p, size - 1);
    }
}

queue<Punt> elimina_punts(queue<Punt> c, Punt p)
{
    int size = c.size();
    elimina_punts_aux(c, p, size);
    return c;
}