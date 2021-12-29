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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> ht;
        while (head != NULL) {
            if (ht.count(head)) {
                return true;
            }
            ht.insert(head);
            head = head->next;
        }
        return false;
    }
};
