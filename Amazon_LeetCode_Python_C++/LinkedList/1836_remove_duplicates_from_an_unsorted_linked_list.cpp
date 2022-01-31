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
    unordered_map<int, int> mp;
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if (!head) {
            return NULL;
        }
        mp[head->val]++;
        head->next = deleteDuplicatesUnsorted(head->next);
        
        if (mp[head->val] > 1) {
            return head->next;
        }
        else {
            return head;
        } 
    }
};
