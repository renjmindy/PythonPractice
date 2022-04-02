# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  
    def inOrder(self, root: Optional[TreeNode], ans: List[int]):
      if root == None:
        return ans
      self.inOrder(root.left, ans)
      ans.append(root.val)
      self.inOrder(root.right, ans)
  
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
      ans = list()
      self.inOrder(root, ans)
      return ans[k - 1]
