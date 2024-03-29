#include <iostream>
#include <vector>
using namespace std;

struct producte {
  int codi;
  double preu;
};

void resultats(vector<int> u, vector<producte> v) 
{
  int prod=0;
  vector<int> w(99901, 0);
  for (unsigned int i=0; i<u.size(); ++i) ++w[u[i]-100];
  for (unsigned int i=0; i<99901; ++i) {
    if (w[i]!=0) ++prod;
  }
  cout<<"Productes diferents: "<<prod<<endl;
  double total=0;
  for (int i=0; i<99901; ++i) {
    if (w[i]!=0) {
      for (unsigned int j=0; j<v.size(); ++j) {
        producte p;
        p=v[j];
        if (i+100==p.codi) total+=w[i]*p.preu;
      }
    }
  }
  cout<<"Total sense descompte: "<<total<<endl;
  double desc=0;
  for (int i=0; i<99901; ++i) {
    while (2<w[i]) {
      for (unsigned int j=0; j<v.size(); ++j) {
        producte p;
        p=v[j];
        if (i+100==p.codi) desc-=p.preu;
      }
      w[i]=w[i]-3;
    }
  }
  cout<<"Descompte: "<<desc<<endl;
  cout<<"Total amb descompte: "<<total+desc<<endl;
}

int main () 
{
  int n;
  cin >> n;
  vector<producte> v(n);
  for (int i=0; i<n; ++i) {
    producte p;
    cin>>p.codi>>p.preu;
    v[i]=p;
  }

  vector<int> u(0);
  int a;
  cin>>a;
  while (a!=-1) { 
   u.push_back(a);
   cin>>a;
  }

  resultats(u, v);
}
