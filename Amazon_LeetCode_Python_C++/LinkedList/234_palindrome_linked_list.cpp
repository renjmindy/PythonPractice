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
    ListNode *p;
    
private:
    bool reversedCheck(ListNode *cur) {
        if (cur != NULL) {
            if (!reversedCheck(cur->next)) {
                return false;
            }
            if (cur->val != p->val) {
                return false;
            }
            p = p->next;
        }
        return true;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        p = head;
        return reversedCheck(head);
    }
};
