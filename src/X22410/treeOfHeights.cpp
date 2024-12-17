#include "treeOfHeights.hpp"

void treeOfHeights_aux(BinaryTree<int>& t) // Fita: t.height()
{

	int height_left = 0;
	int height_right = 0;
	
	if (not t.getLeft().isEmpty()) {
		// HI: t.getLeft().getRoot() = max(height of t.getLeft() children)
		treeOfHeights_aux(t.getLeft()); 
		height_left = t.getLeft().getRoot();
	}
	
	if (not t.getRight().isEmpty()) {
		// HI: t.getRight().getRoot() = max(height of t.getRight() children)
		treeOfHeights_aux(t.getRight()); 
		height_right = t.getRight().getRoot();
	}
	
	t.getRoot() = 1 + max(height_left, height_right);
}

BinaryTree<int> treeOfHeights(BinaryTree<int> t)
{
	if (not t.isEmpty()) treeOfHeights_aux(t);
	return t;
}