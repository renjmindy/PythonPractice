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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *list1 = headA, *list2 = headB;
      while (list1 != list2) {
        list1 = list1 ? list1->next : headB;
        list2 = list2 ? list2->next : headA;
      }
      return list1;
    }
};
