# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None or root == p or root == q:
          return root
        
        lcal = self.lowestCommonAncestor(root.left, p, q)
        lcar = self.lowestCommonAncestor(root.right, p, q)
        
        if lcal and lcar:
          return root
        elif lcal:
          return lcal
        else:
          return lcar
