/*Given a binary tree, find its minimum depth.
*
*The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    int minDepth(TreeNode *root){
       if(!root)
           return 0;

       int depth = 0;
       int mindep = INT_MAX;
       findMinDepth(root, depth, mindep);
       return mindep;
    }
private:
    void findMinDepth(TreeNode *root, int depth, int &mindep);
};

void Solution::findMinDepth(TreeNode *root, int depth, int &mindep){
    if(!root->left && !root->right){
        ++depth;
        mindep = mindep > depth ? depth : mindep;
        return;
    }
    depth++;
    
    if(root->left)
        findMinDepth(root->left, depth, mindep);
    if(root->right)
        findMinDepth(root->right, depth, mindep);
}
