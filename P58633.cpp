#include <iostream>
#include <vector>
using namespace std;

struct Racional {int num, den;};

int potencia (int a, int b) 
{
    int c = 1;
    for (int i = 1; i <=b; ++i) c *= a;
    return c;
}

int vector_a_int(vector<int> v) 
{
    int mida=v.size();
    int a=0;
    for (int i=0; i<mida; ++i) {
        a+=v[mida-1-i]*potencia(10, i);
    }
    return a;
}

Racional llegueix_racional(string s) 
{
    Racional r;
    vector<int> vnum;
    unsigned int i=0;
    while (s[i]!='/') {
        int p=s[i]-48;
        vnum.push_back(p);
        ++i;
    }
    ++i;
    vector<int> vden;
    while (i<s.size()) {
        int p=s[i]-48;
        vden.push_back(p);
        ++i;
    }
    r.num=vector_a_int(vnum);
    r.den=vector_a_int(vden);
    return r;
}

Racional minim(const Racional& a, const Racional& b) 
{
    Racional ra, rb, min;
    ra.num = a.num*b.den;
    rb.num = b.num*a.den;
    if (ra.num < rb.num) min = a;
    else min = b;
    return min;
}

int main () 
{
    int n;
    cin>>n;
    vector<Racional> v1(n);
    for (int i=0; i<n; ++i) {
        string s;
        cin>>s;
        v1[i]=llegueix_racional(s);
    }
    vector<Racional> v2(n);
    for (int i=0; i<n; ++i) {
        string s;
        cin>>s;
        v2[i]=llegueix_racional(s);
    }
    for (int i=0; i<n; ++i) {
        Racional m=minim(v1[i], v2[i]);
        cout<<m.num<<'/'<<m.den<<endl;
    }
}
