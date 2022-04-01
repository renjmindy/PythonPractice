# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # find middle
        f, s = head, head
        while f and f.next:
          f = f.next.next
          s = s.next
          
        # reverse middle-tail
        pre, cur = None, s
        while cur:
          next = cur.next
          cur.next = pre
          pre = cur
          cur = next
        
        # merge head-middle & middle-tail
        f, s = head, pre
        while s.next:
          next = f.next
          f.next = s
          f = next
          
          next = s.next
          s.next = f
          s = next
