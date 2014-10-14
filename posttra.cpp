#include <iostream>
#include <stack>
#include <vector>

using namespace std;
//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root);
private:
	std::stack<TreeNode*> path;
	std::vector<int>	  seqence;
};

vector<int> Solution::postorderTraversal(TreeNode *root){
	//iterativly visit the binary tree
	//path.push(root);
	if(!root)
		return seqence;
	TreeNode *node = root;
	TreeNode *temp = (TreeNode*)LONG_MAX;
	do{
		//·ÀÖ¹ÖØ×ßnode != temp
		if (node->left && node->left != temp && node->right != temp){
			path.push(node);
			node = node->left;
			continue;
			}
		if (node->right && node->right != temp){
			path.push(node);
			node = node->right;
			continue;
		}

		seqence.push_back(node->val);
		if (path.empty()){
			break;
		}

		temp = node;
  		node = path.top();
		path.pop();
	} while (1);

	return seqence;
}
void constructbtree(TreeNode *&root, int i){
	if (i > 9) return;
	root = new TreeNode(i);
	constructbtree(root->left,  ++i);
	constructbtree(root->right, ++i);
}
int main(){
	TreeNode *node = nullptr,*root = new TreeNode(1);
	constructbtree(node, 1);
	/*TreeNode *left = new TreeNode(2);
	root->left = left;
	left->right = new TreeNode(3);*/

	Solution sol;
	sol.postorderTraversal(node);
	return 0;
}