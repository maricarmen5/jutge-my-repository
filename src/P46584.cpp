#include <iostream>
#include <vector>
using namespace std;

vector<double> diferencia(const vector<double>& v1, const vector<double>& v2) 
{
    vector<double> v;

    int i = 0;
    int j = 0;
    int m1 = v1.size();
    int m2 = v2.size();
    while (i < m1 and j < m2) {
        // v es v1(0...i) sense elements trobats a v2(0...j)
        if (v1[i] == v2[j]) ++i;
        else if (v1[i] < v2[j]) {
            if (v.size() == 0 or v1[i] != v[v.size() - 1]) {
                v.push_back(v1[i]);
            }
            ++i;
        } 
        else ++j;
    }

    while (i < m1) {
        if (v.size() == 0 or v1[i] != v[v.size() - 1]) {
            v.push_back(v1[i]);
        }
        ++i;
    }
    
    return v;
}
