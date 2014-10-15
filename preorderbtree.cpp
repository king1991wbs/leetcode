/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root);
};

vector<int> Solution::preorderTraversal(TreeNode *root){
	vector<int >     sequence;
	stack<TreeNode*> path;

	if(!root) return sequence;

	TreeNode *node = root,*temp = root;
	//visit
	sequence.push_back(root->val);
	do{
		//visit left branch
		if(node->left && node->left != temp && node->right != temp){
			path.push(node);
			node = node->left;
			sequence.push_back(node->val);
			continue;
		}
		//visit right branch
		if(node->right && node->right != temp){
			path.push(node);
			node = node->right;
			sequence.push_back(node->val);
			continue;
		}

		if (path.empty()) break;
		temp = node;
		node = path.top();
		path.pop();
	}while(1);

	return sequence;
}