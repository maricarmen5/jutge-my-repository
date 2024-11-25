#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> cuaCreixent;
    priority_queue<int> cuaDecreixent;

    int enter;
    while (cin >> enter) {
        cuaCreixent.push(enter);
        cuaDecreixent.push(-enter);
    }

    while (not cuaDecreixent.empty()) {
        cout << -cuaDecreixent.top();
        if (1 < cuaDecreixent.size()) cout << ' ';
        cuaDecreixent.pop();
    }
    cout << endl;
    
    while (not cuaCreixent.empty()) {
        cout << cuaCreixent.top();
        if (1 < cuaCreixent.size()) cout << ' ';
        cuaCreixent.pop();
    }
    cout << endl;
}