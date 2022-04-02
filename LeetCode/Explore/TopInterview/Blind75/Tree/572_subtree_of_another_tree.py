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
      return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
  
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if root == None:
          return False
        if subRoot == None:
          return True
        if self.isSameTree(root, subRoot):
          return True
        
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
