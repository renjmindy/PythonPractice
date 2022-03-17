// Complexity Analysis
// Time complexity: \mathcal{O}(N)O(N). There are three steps here. To identify the middle node takes \mathcal{O}(N)O(N) time. 
// To reverse the second part of the list, one needs N/2N/2 operations. The final step, to merge two lists, requires N/2N/2 operations as well. 
// In total, that results in \mathcal{O}(N)O(N) time complexity.
// Space complexity: \mathcal{O}(1)O(1), since we do not allocate any additional data structures.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  void reorderList(ListNode* head) {
    if (!head) { // base case
      return;
    }
    // Middle of the Linked List.
    ListNode *f = head, *s = head;
    while (f && f->next) {
      f = f->next->next;
      s = s->next;
    }
    // Reverse Linked List.
    ListNode *pre = nullptr, *cur = s, *next;
    while (cur) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    // Merge Two Sorted Lists.
    f = head, s = pre;
    while (s->next) {
      next = f->next;
      f->next = s; // reverse f
      f = next;
            
      next = s->next;
      s->next = f; // reverse s
      s = next;
    }
  }
};
