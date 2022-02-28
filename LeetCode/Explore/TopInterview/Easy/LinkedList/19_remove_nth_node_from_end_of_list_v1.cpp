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
    ListNode *d = new ListNode(0);
    d->next = head;
    ListNode *f = head;
    int len = 0;
    while (f) {
      len++;
      f = f->next;
    }
    len -= n;
    f = d;
    while (len) {
      len--;
      f = f->next;
    }
    f->next = f->next->next;
    return d->next;
  }
};
