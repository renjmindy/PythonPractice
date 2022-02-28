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
    // if we reached the end, then the previous node must be the head of the reversed list
    if (!head) {
      return pre;
    }
    ListNode *next = head->next; // Remember the next node
    head->next = pre; // Reverse the current node
    return reverseList(next, head); // Reverse the remainder of the list
  }
};
