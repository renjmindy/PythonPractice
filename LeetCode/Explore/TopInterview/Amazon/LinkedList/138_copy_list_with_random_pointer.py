"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
  
    def __init__(self):
    # Dictionary which holds old nodes as keys and new nodes as its values.
      self.mp = dict()
  
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head == None:
          return None
          
         # If we have already processed the current node, then we simply return the cloned version of it.
        if head in self.mp.keys():
          return self.mp[head]
        else:
         # create a new node
         # with the value same as old node.
          h = Node(head.val)
         # Save this value in the hash map. This is needed since there might be
         # loops during traversal due to randomness of random pointers and this would help us avoid them.
          self.mp[head] = h
         # Recursively copy the remaining linked list starting once from the next pointer and then from the random pointer.
         # Thus we have two independent recursive calls.
         # Finally we update the next and random pointers for the new node created.
          h.next = self.copyRandomList(head.next)
          h.random = self.copyRandomList(head.random)
          return h
