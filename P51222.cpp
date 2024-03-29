#include <iostream>
#include <vector>
using namespace std;

int nombre_digits(int n) 
{
	int d = 1;
	if (9 < n) d = 1 + nombre_digits(n/10);
	return d;
}
