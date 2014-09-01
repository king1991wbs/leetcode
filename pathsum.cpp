#include <iostream>
#include <vector>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    std::vector<std::vector<int> > pathSum(TreeNode *root, int sum) {
		std::vector<std::vector<int> > pathsSet;
		std::vector<int> path;

		if(!root) return pathsSet;

		int pathVal = 0;

		_aux_pathSum(root ,sum , pathVal, pathsSet, path);

		return pathsSet;
    }
private:
	void _aux_pathSum(TreeNode *root,const int sum, int pathVal, std::vector<std::vector<int> > &pathsSet, std::vector<int> path);
};

void Solution::_aux_pathSum(TreeNode *root,const int sum, int pathVal, std::vector<std::vector<int> > &pathsSet, std::vector<int> path){
	
	pathVal += root->val;
	path.push_back(root->val);

	if(!root->left && !root->right && sum == pathVal)
	{
		//pathVal += root->val;
		//path.push_back(root->val);
		//if(sum == pathVal)
			pathsSet.push_back(path);
		//path.pop_back()
		return;
	}

	
	//±éÀú×ó±ß
	if(root->left)
	{
		//pathVal += root->val;
		//path.push_back(root->val);
		_aux_pathSum(root->left, sum, pathVal, pathsSet, path);
		//path.pop_back();
	}
	//±éÀúÓÒ±ß
	if(root->right)
	{
		//pathVal += root->val;
		//path.push_back(root->val);
		_aux_pathSum(root->right, sum, pathVal, pathsSet, path);
		//path.pop_back();
	}
	path.pop_back();
}

int main()
{
	Solution sol;
	TreeNode *root = new TreeNode(1);
	//root->left = NULL;
	//root->right = NULL;

	TreeNode *left = new TreeNode(2);
	root->left = left;

	int sum = 20;

	sol.pathSum(root, sum);
	return 0;
}