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
  ListNode* reverseList(ListNode *head, ListNode *pre = nullptr) {
    if (!head) {
      return pre;
    }
    
    ListNode *next = head->next;
    head->next = pre;
    // pre = head;
    // head = next;
    return reverseList(next, head);
  } 
  
  ListNode *additions(ListNode *l1, ListNode *l2, int carry) {
    if (!l1 && !l2 && !carry) {
      return nullptr;
    }
    int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
    carry = sum / 10;
    sum %= 10;
    ListNode *p = new ListNode(sum);
    p->next = additions((l1 && l1->next ? l1->next : nullptr), (l2 && l2->next ? l2->next : nullptr), carry);
    return p;
  }
  
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      l1 = reverseList(l1);
      l2 = reverseList(l2);
      int carry = 0;
      ListNode *p = additions(l1, l2, carry);
      return reverseList(p);
    }
};
