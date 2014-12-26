//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Definition for binary tree
#include <iostream>


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(!root) return 0;

	int depth = 1;
	int L = depth, R = depth;

	_maxDepth(root->left, L);
        _maxDepth(root->right, R);

	return std::max(L, R);
    }
private:
    void _maxDepth(TreeNode *root, int &depth){
    	if(!root) return;

	depth++;
	int L = depth, R = depth;
	_maxDepth(root->left, L);
	_maxDepth(root->right, R);

	depth = std::max(L, R);
    }
};
