/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 */

#include <iostream>

using namespace std;


// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
    	if( NULL == root )
    		return true;
        int pre;
        first = true;
        invalid = false;
        validBST(root, pre);
        return !invalid;
    }
private:
	void validBST(TreeNode * root, int & pre);
private:
	bool first;
	bool invalid;
};
void Solution::validBST(TreeNode * root, int  & pre){
	if( !invalid && root->left )
		validBST( root->left, pre );
	if( !invalid && first ){
		//pre = root->val;
		first = false;
	}else if( !invalid &&pre >= root->val ){
			invalid = true;
			return;
		}
	pre = root->val;
	if( !invalid && root->right )
		validBST( root->right, pre );
}
int main(){

	return 0;
}