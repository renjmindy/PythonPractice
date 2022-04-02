# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode], MIN=-math.inf, MAX=math.inf) -> bool:
        if root == None:
          return True
        
        if root.val <= MIN or root.val >= MAX:
          return False
        
        return self.isValidBST(root.left, MIN, root.val) and self.isValidBST(root.right, root.val, MAX)
