#include <iostream>
#include <queue>
using namespace std;

// Pre:  Siguin [a1,a2,...,an] i [b1,b2,...,bm] els valors inicials de q1 i q2, respectivament.
// Post: En el cas n>=m, la cua retornada és [a1,b1,a2,b2,...,am,bm,a{m+1},a{m+2},...,an].
//       En el cas n<m, la cua retornada és [b1,a1,b2,a2,...,bn,an,b{n+1},b{n+2},...,bm].
queue<int> intercal(queue<int> q1, queue<int> q2)
{
    int n = q1.size();
    int m = q2.size();
    if (n < m) {
        swap(q1, q2); 
        swap(n, m);
    } // q1 ha de ser més llarga que q2

    queue<int> q;

    while (not q2.empty()) {
        q.push(q1.front());
        q.push(q2.front());

        q1.pop();
        q2.pop();
    }

    while (not q1.empty()) {
        q.push(q1.front());
        q1.pop();
    }

    return q;
}

int main() {}