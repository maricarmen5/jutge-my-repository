#include <iostream>
#include "list_punt_separa.hpp"
#include "Punt.hpp"
using namespace std;

void separa(list<Punt> &lp, float x, list<Punt> &lp1, list<Punt> &lp2) 
{
  while (not lp.empty()) {
    Punt p = lp.front();
    
    if (p.coordenadax() < x) lp1.push_back(p);
    else if (x < p.coordenadax()) lp2.push_back(p);
    
    lp.pop_front();
  }
}