#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

void reverseQueue_aux(queue<int>& q, int size)
{
    if (1 < size) {
        int front = q.front();
        q.pop();

        reverseQueue_aux(q, size - 1);
        
        q.push(front);
    }
}

queue<int> reverseQueue(queue<int> q)
{
    int size = q.size();
    reverseQueue_aux(q, size);
    return q;
}

int main () {}