/**
  Definition for binary tree*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
    	if(!root) return true;

    	TreeNode *mirror_root = root;
    	queue<TreeNode*> origin, mirror;
    	origin.push(root);
    	mirror.push(root);

    	while(!origin.empty() && !mirror.empty()){
    		root = origin.front();
    		origin.pop();
    		mirror_root = mirror.front();
    		mirror.pop();
			if (root->val != mirror_root->val)
				return false;

    		if((!root->left && mirror_root->right) || (root->left && !mirror_root->right))
    			return false;
    		if(root->left && mirror_root->right){
    			origin.push(root->left);
    			mirror.push(mirror_root->right);
    		}

    		if((!root->right && mirror_root->left) || (root->right && !mirror_root->left))
    			return false;
    		if(root->right && mirror_root->left){
    			origin.push(root->right);
    			mirror.push(mirror_root->left);
    		}
    	}
    	if(origin.empty() && mirror.empty())
    		return true;
    	return  false;
    }
}; 

int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution sol;
	cout << sol.isSymmetric(root);
	return 0;
}