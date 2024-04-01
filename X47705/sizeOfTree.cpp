#include "sizeOfTree.hpp"

// Retorna la mida de t
int sizeOfTree_aux(BinaryTree<int>& t) 
{
  int ans = 0;
  if (not t.isEmpty ()) ans = 1 + sizeOfTree_aux(t.getLeft()) + sizeOfTree_aux(t.getRight());
  return ans;
}

int sizeOfTree(BinaryTree<int> t) 
{
  int ans = sizeOfTree_aux(t);
  return ans;
}