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
  
private:
  ListNode *fp;
  
  bool reverseList(ListNode *cur) {
    if (cur) {
      if (!reverseList(cur->next)) {
        return false;
      }
      if (cur->val != fp->val) {
        return false;
      }
      fp = fp->next;
    }
    return true;
  }
  
public:
    bool isPalindrome(ListNode* head) {
      fp = head;
      return reverseList(head);
    }
};
