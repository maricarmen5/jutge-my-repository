#include <iostream>
#include <list>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"
using namespace std;

void LlegirLlistaParInt(list<ParInt>& l)
{
	ParInt p;
	
	while (p.llegir()) {
		l.push_back(p);
	}
}