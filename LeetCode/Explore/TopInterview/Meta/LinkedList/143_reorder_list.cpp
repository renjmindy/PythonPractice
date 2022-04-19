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
      ListNode *f = head, *s = head;
      while (f && f->next) {
        f = f->next->next;
        s = s->next;
      }
      ListNode *pre = nullptr, *cur = s, *next;
      while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
      f = head, s = pre;
      while (s->next) {
        next = f->next;
        f->next = s;
        f = next;
        
        next = s->next;
        s->next = f;
        s = next;
      }
    }
};
