// Fast and Slow Pointer

// Complexity Analysis
// Time Complexity: O(N)O(N), where NN is the number of nodes in the given list.
// Space Complexity: O(1)O(1), the space used by slow and fast.

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
  ListNode* middleNode(ListNode* head) {
    ListNode *f = head, *s = head;
    while (f && f->next) {
      f = f->next->next;
      s = s->next;
    }
    return s;
  }
};
