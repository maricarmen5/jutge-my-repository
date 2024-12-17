#include <iostream>
using namespace std;

int main () 
{
    char polyhedron;
    double x, y, z;
    cin >> polyhedron >> x >> y >> z;

    double volum = 0;
    if (polyhedron == 'C') volum = x*y*z;
    else if (polyhedron == 'R') volum = (1/3.0)*x*y*z;
    else volum = 5*x*(1/2.0)*y*z;

    cout << volum << endl;
}