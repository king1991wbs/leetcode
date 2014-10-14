# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def __init__(self):
        self.post_sequence = []

    def postorderTraversal(self, root):
        if root == None:
            return self.post_sequence
        self.postorderTraversal(root.left)
        self.postorderTraversal(root.right)
        #print root.val
        self.post_sequence.append(root.val)
        return self.post_sequence