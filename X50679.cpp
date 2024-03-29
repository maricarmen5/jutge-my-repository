#include <iostream>
#include <vector>
using namespace std;

typedef vector < vector<int> > matriu;

struct Resultat {
  vector< vector<int> > matriu;
  int canviat;
};

Resultat matriu0(const vector< vector<int> > &mat) 
{
  Resultat matriu0;
  matriu0.matriu=mat;
  matriu0.canviat=0;
  bool trobat=false;
  for (unsigned int i=0; i<mat.size(); ++i) {
    trobat=false;
    unsigned int j=0;
    while ((j<mat[0].size())and(not trobat)) {
      if (mat[i][j]==0) {
        trobat=true;
        for (unsigned int k=0; k<mat.size(); ++k) matriu0.matriu[k][j]=0; 
        for (unsigned int k=0; k<mat[0].size(); ++k) matriu0.matriu[i][k]=0; 
      } else ++j;
    }
  }
  for (unsigned int i=0; i<mat.size(); ++i) {
    for (unsigned int j=0; j<mat[0].size(); ++j) {
      if (matriu0.matriu[i][j]!=mat[i][j]) ++matriu0.canviat;
    }
  }
  
  return matriu0;
}
