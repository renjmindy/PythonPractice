# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        f, s = head, head
        
        while (n):
          f = f.next
          n -= 1
          
        if f == None:
          return head.next
        else:
          while f.next:
            f = f.next
            s = s.next
          
        s.next = s.next.next
        return head  
