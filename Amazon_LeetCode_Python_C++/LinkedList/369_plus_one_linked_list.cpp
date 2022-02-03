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
    void additions(ListNode* p, int &carry, int &sum) {
        if (!p) {
            return;
        }
        additions(p->next, carry, sum);
        sum = carry + p->val;
        carry = sum / 10;
        sum %= 10;
        p->val = sum;
    }
    
public:
    ListNode* plusOne(ListNode* head) {
        int sum = 0, carry = 1;
        additions(head, carry, sum);
        if (carry > 0) {
            head = new ListNode(carry, head);
        }
        return head;
    }
};
