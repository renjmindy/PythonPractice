// Compare one by one by Priority Queue

// Complexity Analysis
// Time complexity : O(N\log k)O(Nlogk) where \text{k}k is the number of linked lists.
// The comparison cost will be reduced to O(\log k)O(logk) for every pop and insertion to priority queue. 
// But finding the node with the smallest value just costs O(1)O(1) time.
// There are NN nodes in the final linked list.
// Space complexity :
// O(n)O(n) Creating a new linked list costs O(n)O(n) space.
// O(k)O(k) The code above present applies in-place method which cost O(1)O(1) space. 
// And the priority queue (often implemented with heaps) costs O(k)O(k) space (it's far less than NN in most situations).

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
    priority_queue<P, vector<P>, greater<P>> pq; // ascending order
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i]) {
        pq.push({lists[i]->val, lists[i]});
      }
    }
    auto dum = new ListNode();
    auto cur = dum;
    while(!pq.empty()) {
      auto top = pq.top();
      pq.pop();
      cur->next = top.second;
      cur = cur->next;
      if (cur->next) {
        pq.push({cur->next->val, cur->next});
      }
    }
    return dum->next;
  }
};
