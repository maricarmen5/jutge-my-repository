#include "searchInBST.hpp"

bool searchInBST(BinaryTree<int> &t, int x) {
	bool ans = false;
	
    if (not t.isEmpty()) {
        int n = t.getRoot();

        if (x == n) ans = true;
        else if (x < n) ans = searchInBST(t.getLeft(), x);
        else ans = searchInBST(t.getRight(), x);
        
    }

	return ans;
}