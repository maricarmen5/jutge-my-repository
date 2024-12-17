#include <iostream>
#include <queue>
using namespace std;

queue<int> remove01(queue<int> q)
{
    int size = q.size();
    for (int i = 0; i < size; ++i) {
        int front = q.front();

        if ((front == 0 and i%2 != 0) 
        or (front == 1 and i%2 == 0) 
        or (front != 0 and front!= 1)) q.push(front);

        q.pop();
    }

    return q;
}
