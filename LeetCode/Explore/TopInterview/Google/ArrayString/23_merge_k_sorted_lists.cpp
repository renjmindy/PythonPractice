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
      priority_queue<P, vector<P>, greater<P> > pq;
      for (auto &list : lists) {
        if (list) {
          pq.push(make_pair(list->val, list));
        }
      }
      ListNode *dummy = new ListNode();
      ListNode *curptr = dummy;
      while (pq.size()) {
        auto topvar = pq.top();
        pq.pop();
        curptr->next = topvar.second;
        curptr = curptr->next;
        if (curptr->next) {
          pq.push(make_pair(curptr->next->val, curptr->next));
        }
      }
      return dummy->next;
    }
};
