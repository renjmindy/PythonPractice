/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  
private:
  unordered_map<Node*, Node*> mp;
  
public:
    Node* copyRandomList(Node* head) {
      if (!head) {
        return head;
      }
      if (mp.count(head)) {
        return mp[head];
      } 
      else {
        Node *h = new Node(head->val);
        mp[head] = h;
        h->next = copyRandomList(head->next);
        h->random = copyRandomList(head->random);
        return h;
      }
    }
};
