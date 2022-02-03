/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *f = head, *s = head;
        while (f && f->next) {
            f = f->next->next;
            s = s->next;
            if (f == s) {
                break;
            }
        }
        if (!(f && f->next)) {
            return NULL;
        }
        while (head != s) {
            s = s->next;
            head = head->next;
        }
        return head;
    }
};
