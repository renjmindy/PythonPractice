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
        if (head == NULL) {
            return;
        }
        ListNode *f = head;
        ListNode *s = head;
        while (f != NULL && f->next != NULL) {
            f = f->next->next;
            s = s->next;
        }
        ListNode *pre = NULL;
        ListNode *cur = s;
        ListNode *tmp;
        while (cur != NULL) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        f = head;
        s = pre;
        while (s->next != NULL) {
            tmp = f->next;
            f->next = s;
            f = tmp;
            
            tmp = s->next;
            s->next = f;
            s = tmp;
        }
    }
};
