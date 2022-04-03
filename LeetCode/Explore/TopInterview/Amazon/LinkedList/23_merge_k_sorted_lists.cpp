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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      typedef pair<int, ListNode*> P;
      priority_queue<P, vector<P>, greater<P> > pq; // descending
      for (auto &list : lists) {
        if (list) {
          pq.push(make_pair(list->val, list));
        }
      }
      auto dummy = new ListNode();
      auto curptr = dummy;
      while (pq.size()) {
        auto toptr = pq.top();
        pq.pop();
        curptr->next = toptr.second;
        curptr = curptr->next;
        if (curptr->next) {
          pq.push(make_pair(curptr->next->val, curptr->next));
        }
      }
      return dummy->next;
    }
};
