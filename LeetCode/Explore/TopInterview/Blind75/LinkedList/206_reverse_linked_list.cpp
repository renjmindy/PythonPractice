// Complexity analysis
// Time complexity : O(n)O(n). Assume that nn is the list's length, the time complexity is O(n)O(n).
// Space complexity : O(n)O(n). The extra space comes from implicit stack space due to recursion. The recursion could go up to nn levels deep.

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
  ListNode* reverseList(ListNode* head, ListNode *pre = nullptr) {
    if (!head) { // base case
      return pre;
    }
    ListNode *next = head->next;
    head->next = pre;
    return reverseList(next, head);
  }
};
