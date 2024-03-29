#include <iostream>
#include <vector>
using namespace std;

// merge sort
vector<double> fusio(const vector<double>& v1, const vector<double>& v2) 
{
    vector<double> v;

    int i = 0;
    int j = 0;
    int m1 = v1.size();
    int m2 = v2.size();
    while (i < m1 and j < m2) {
        if (v1[i] < v2[j]) {
            v.push_back(v1[i]);
            ++i;
        } 
        else {
            v.push_back(v2[j]);
            ++j;
        }
    }

    while (i < m1) {
        v.push_back(v1[i]);
        ++i;
    }

    while (j < m2) {
        v.push_back(v2[j]);
        ++j;
    }

    return v;
}
