#include <iostream>
#include <vector>
using namespace std;

vector<int> concatenacio(const vector<int>& v1, const vector<int>& v2) 
{
    int m1 = v1.size();
    int m2 = v2.size();
    
    vector<int> v(m1 + m2);
    for (int i = 0; i < m1; ++i) v[i] = v1[i];
    for (int i = 0; i < m2; ++i) v[m1 + i] = v2[i];
    
    return v;
}
