#include "longestLeftmostPath.hpp"

void treeOfHeights(BinaryTree<int>& t)
{
	int height_left = 0;
	int height_right = 0;
	
	if (not t.getLeft().isEmpty()) {
		treeOfHeights(t.getLeft()); 
        height_left = t.getLeft().getRoot();
	}
	
	if (not t.getRight().isEmpty()) {
		treeOfHeights(t.getRight()); 
		height_right = t.getRight().getRoot();
	}
	
	t.getRoot() = 1 + max(height_left, height_right);
}

void longestLeftmostPath_aux(BinaryTree<int>& original_t, BinaryTree<int>& t, list<int>& l)
{
    // Fita: height of t.
    if (1 < t.getRoot()) {
        l.push_back(original_t.getRoot());

        if (t.getLeft().isEmpty()) {
            longestLeftmostPath_aux(original_t.getRight(), t.getRight(), l); 
            // HI: rigth child of t has the longest path of t
        }
        else if (t.getRight().isEmpty()) {
            longestLeftmostPath_aux(original_t.getLeft(), t.getLeft(), l); 
            // HI: left child of t has the longest path of t
        }
        else if (t.getLeft().getRoot() < t.getRight().getRoot()) {
            longestLeftmostPath_aux(original_t.getRight(), t.getRight(), l);
        }
        else longestLeftmostPath_aux(original_t.getLeft(), t.getLeft(), l);
    }
    else l.push_back(original_t.getRoot());
}

list<int> longestLeftmostPath(BinaryTree<int> t)
{
    BinaryTree<int> original_t = t;
    treeOfHeights(t);

    list<int> l;
    longestLeftmostPath_aux(original_t, t, l);
    return l;
}