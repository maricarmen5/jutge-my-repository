#include <iostream>
#include <queue>
using namespace std;

queue<int> uniq(queue<int> q)
{
    int size = q.size();
    for (int i = 0; i < size; ++i) {
        int front = q.front();
        q.pop();

        if (front != q.front()) q.push(front);
    }
    return q;
}

int main() {}