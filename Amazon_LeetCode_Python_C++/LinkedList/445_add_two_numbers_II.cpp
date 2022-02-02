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
    ListNode* reversedList(ListNode *head, ListNode *tail = nullptr) {
        if (!head) {
            return tail;
        }
        swap(head->next, tail);
        return reversedList(tail, head);
    }
        
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reversedList(l1);
        l2 = reversedList(l2);
        
        ListNode *p = nullptr;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = sum / 10;
            sum %= 10;
            ListNode *cur = new ListNode(sum);
            cur->next = p;
            p = cur;
            
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if (carry != 0) {
            ListNode *cur = new ListNode(carry);
            cur->next = p;
            p = cur;
        }
        return p;
    }
};
