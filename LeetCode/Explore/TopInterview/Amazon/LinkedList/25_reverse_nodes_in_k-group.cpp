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
  ListNode* reverseLinkedList(ListNode *head, int k) {
    ListNode *pre = nullptr;
    
    while (k) {
      ListNode *next = head->next;
      head->next = pre;
      pre = head;
      head = next;
      k--;
    }
    return pre;
  }
  
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      int counter = 0;
      ListNode *pre = head;
      while (counter < k && pre) {
        pre = pre->next;
        counter++;
      }
      if (counter == k) {
        ListNode *reverseHead = reverseLinkedList(head, k);
        head->next = reverseKGroup(pre, k);
        return reverseHead;
      }
      return head;
    }
};
