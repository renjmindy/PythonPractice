# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  
    def preOrder(self, root: Optional[TreeNode], level: int, ans: List[List[int]]):
      if root == None:
        return
      if len(ans) == level:
        ans.append([root.val])
      else:
        ans[level].append(root.val)

      if root.left:
        self.preOrder(root.left, level + 1, ans)
      
      if root.right:
        self.preOrder(root.right, level + 1, ans)
  
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = list()
        self.preOrder(root, 0, ans)
        return ans
