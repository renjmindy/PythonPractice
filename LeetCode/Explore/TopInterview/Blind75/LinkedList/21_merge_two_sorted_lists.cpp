// Recursion

// Complexity Analysis
// Time complexity : O(n + m)O(n+m)
// Because each recursive call increments the pointer to l1 or l2 by one (approaching the dangling null at the end of each list), there will be exactly one call 
// to mergeTwoLists per element in each list. Therefore, the time complexity is linear in the combined size of the lists.
// Space complexity : O(n + m)O(n+m)
// The first call to mergeTwoLists does not return until the ends of both l1 and l2 have been reached, so n + mn+m stack frames consume O(n + m)O(n+m) space.

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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) {
      return list2;
    }
    if (!list2) {
      return list1;
    }
    if (list1->val > list2->val) { // traverse smaller nodes first 
      list2->next = mergeTwoLists(list1, list2->next);
      return list2;
    }
    else {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    }
  }
};
