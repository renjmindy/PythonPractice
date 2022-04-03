# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]):
      if p == q:
        return True
      if p == None or q == None:
        return False
      return p.val == q.val and self.isSameTree(p.left, q.right) and self.isSameTree(p.right, q.left)
  
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
      if root == None:
        return True
      return self.isSameTree(root.left, root.right)
