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

// Recursion makes the code more self explanatory as it is only required to check the current element. 
// If head.val is equal to the given val, then we can simply call recursion on head.next and return that 
// (this is essentially deleting head). If it isn't, then we set the value of head.next equal to the what 
// is returned by recursion when called on head.next and return head.

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      if (!head) {
        return NULL;
      }
      if (head->val == val) {
        head = removeElements(head->next, val);
      }
      else {
        head->next = removeElements(head->next, val);
      }
      return head;
    }
};
