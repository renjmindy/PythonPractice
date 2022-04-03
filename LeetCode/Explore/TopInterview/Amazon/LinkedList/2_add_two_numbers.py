# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  
    def additions(self, l1: Optional[ListNode], l2: Optional[ListNode], carry: int):
      if l1 == None and l2 == None and carry == 0:
        return None
      
      sum = carry
      
      if l1:
        sum += l1.val
        
      if l2:
        sum += l2.val
        
      carry = sum // 10
      sum = sum % 10
      
      p = ListNode(sum)
      
      if l1 and l1.next and l2 and l2.next:
        p.next = self.additions(l1.next, l2.next, carry)
      elif not (l1 and l1.next) and l2 and l2.next:
        p.next = self.additions(None, l2.next, carry)
      elif l1 and l1.next and not (l2 and l2.next):
        p.next = self.additions(l1.next, None, carry)
      elif not (l1 and l1.next) and not (l2 and l2.next):
        p.next = self.additions(None, None, carry)
      
      return p
  
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        return self.additions(l1, l2, 0)
