/*Given two binary trees, write a function to check if they are equal or not.
*
*
* Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/
#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
	public:
		bool isSameTree(TreeNode *p, TreeNode *q){
			if((!p && q) || (p && !q))
				return false;
			if(p && q){
				if(p->val != q->val)
					return false;
				if(!isSameTree(p->left, q->left))
					return false;
				if(!isSameTree(p->right, q->right))
					return false;
			}
			return true;
		}
};

int main(){
	return 0;
}
