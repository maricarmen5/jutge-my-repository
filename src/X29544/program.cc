#include <iostream>
#include <list>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"
using namespace std;

int main () 
{
	list<ParInt> l;
	
	LlegirLlistaParInt(l);
	
	int n;
	cin >> n;
	
	int suma = 0;
	int aparicions = 0;
	
	while (not l.empty()) {
		ParInt p;
		p = l.front();
		
		if (p.primer() == n) {
			++aparicions;
			suma += p.segon();
		}
		
		l.pop_front();
	}
	
	cout << n << ' ' << aparicions << ' ' << suma << endl;
}