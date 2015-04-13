/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.
*/
#include <iostream>
#include <vector>
#include <cstdlib>

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
    vector<TreeNode *> generateTrees(int n) {
    	if( n < 1 )
    		return vector<TreeNode *>(1, NULL);
    	return genBST(1, n);
    }
private:
	vector<TreeNode *> genBST(int i, int j){
		vector<TreeNode *> BST;
		if( i > j ){
			BST.push_back(NULL);
			return BST;
		}
		for( int k = i; k <= j; k++){
			vector<TreeNode *> left = genBST(i, k - 1);
			vector<TreeNode *> right = genBST(k + 1, j);
			for( auto iter1 = left.begin(); iter1 != left.end(); iter1++ ){
				for( auto iter2 = right.begin(); iter2 != right.end(); iter2++ ){
					TreeNode * node = new TreeNode(k);
					node->left = *iter1;
					node->right = *iter2;
					BST.push_back(node);
				}
			}
		}
		return BST;
	}
};

int main( int argc, char *argv[] ){
	Solution sol;
	sol.generateTrees( atoi(argv[1]) );
	return 0;
}