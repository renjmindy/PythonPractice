// One pass algorithm

// Complexity Analysis
// Time complexity : O(L)O(L).
// The algorithm makes one traversal of the list of LL nodes. Therefore time complexity is O(L)O(L).
// Space complexity : O(1)O(1).
// We only used constant extra space.

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *f = head, *s = head;
    while (n) {
      f = f->next;
      n--;
    }
    if (!f) {
      return head->next;
    }
    else {
      while (f->next) {
        f = f->next;
        s = s->next;
      }
      s->next = s->next->next;
      return head;
    }
  }
};
