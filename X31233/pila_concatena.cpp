#include <iostream>
#include <stack>
using namespace std;

// Pre: p = P, q = Q, concatp buida
// Post: concatp conté a dalt els elements de P i a sota els de Q, ambdós
// en el mateix ordre
void concatena_piles (stack<int> &p, stack<int> &q, stack<int> &concatp) {
    int n;
    if (not p.empty()) {
        n=p.top();
        p.pop();
        concatena_piles(p, q, concatp);
        concatp.push(n);
    } else {
        if (not q.empty()) {
            n=q.top();
            q.pop();
            concatena_piles(p, q, concatp);
            concatp.push(n);
        }
    }
}

/*stack<int> read_pila(int m) {
    stack<int> p;
    int n;
    for (int i=0; i<m; ++i) {
        cin>>n;
        p.push(n);
    }
    return p;
}

void write_pila(stack<int> &p) {
    int m=p.size();
    for (int i=0; i<m; ++i) {
        cout<<p.top();
        if (i!=m-1) cout<<'|';
        p.pop();
    }
    cout<<']'<<endl;
}

int main() {
    int m;

    stack<int> p;
    cin>>m;
    p=read_pila(m);

    stack<int> q;
    cin>>m;
    q=read_pila(m);

    stack<int> r;
    concatena_piles(p, q, r);

    cout<<"pila concatenació: ";
    write_pila(r);
}*/
