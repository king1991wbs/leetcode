/*************************************************************************
	> File Name: constructBinaryTree.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Tue 15 Apr 2014 06:15:51 PM CST
 ************************************************************************/

#include<iostream>
#include<assert.h>
using namespace std;

typedef struct node
{
    int nodeVal;
    node *left,*right;
}Node,*pNode;

const int MAX = 256;
int mapIndex[MAX];

void mapToIndices(int inorder[],int n)
{
    for(int i = 0;i < n; i++)
    {
        assert(inorder[i] >= 0 && inorder[i] <= MAX - 1);
        mapIndex[inorder[i]] = i;
    }
}
//construct a binary tree
Node *buildInorderPreorder(int in[],int pre[],int n,int offset)
{
    assert(n >= 0);
    if(n == 0) return NULL;
    int rootVal = pre[0];
    int i = mapIndex[rootVal] - offset;
    Node *root = new Node();
    root->nodeVal = rootVal;
    root->left = buildInorderPreorder(in,pre+1,i,offset);
    root->right = buildInorderPreorder(in+i+1,pre+i+1,n-i-1,offset+i+1);
    return root;
}
//print a binary tree in inorder
void printBinaryTree(pNode root)
{
    if(!root) return;
    cout << root->nodeVal << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

int main()
{
    int preorder[8] = {7,10,4,3,1,2,8,11};
    int inorder[8] = {4,10,3,1,7,11,8,2};
    mapToIndices(inorder,8);

    Node *root = buildInorderPreorder(inorder,preorder,8,0);
    printBinaryTree(root);
    return 0;
}
