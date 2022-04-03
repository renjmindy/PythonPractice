# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  
    def reverseLinkedList(self, head: Optional[ListNode], k: int):
      pre = None
      while k:
        nex = head.next
        head.next = pre
        pre = head
        head = nex
        k -= 1
      return pre
  
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        counter = 0
        pre = head
        
        while counter < k and pre:
          pre = pre.next
          counter += 1
          
        if counter == k:
          reverseHead = self.reverseLinkedList(head, k)
          head.next = self.reverseKGroup(pre, k)
          return reverseHead
        
        return head
