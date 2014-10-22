/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
*
*For example:
*Given the below binary tree and sum = 22,
*              5
*             / \
*            4   8
*           /   / \
*          11  13  4
*         /  \      \
*        7    2      1
*return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
	public:
		bool hasPathSum(TreeNode *root, int sum){
			if(!root) return false;

			int total = 0;
			return pathsum(root, sum, total);
		}
	private:
		bool pathsum(TreeNode *root, int sum, int total);
};

bool Solution::pathsum(TreeNode *root, int sum, int total){
	total += root->val;

	if(!root->left && !root->right && total == sum)
		return true;

	if(root->left && pathsum(root->left, sum, total))
		return true;	
	if(root->right && pathsum(root->right, sum, total))
		return true;

	return false;
}

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);

	Solution sol;
	sol.hasPathSum(root, 3);
	return 0;
}
