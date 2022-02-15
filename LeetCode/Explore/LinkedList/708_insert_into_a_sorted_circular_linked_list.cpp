/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
      // If it gives an empty linked list, it asks us to create and return a new single circular list
      if(!head) {
        Node* ans = new Node(insertVal);
        ans -> next = ans;
        return ans;
      }
      
      Node* search = head;
      while(search -> next != head) {
        // Case 1: The insert node value is between the largest or smallest value in linked list
        // Ex: [3,4,1], insertVal = 5 => [3,4,5,1] or // Ex: [3,4,1], insertVal = 0 => [3,4,0,1]
        if(search->next->val < search->val && (insertVal <= search->next->val || insertVal >= search->val)) break;
        // Case 2: The insert value is smaller than search->next->val and bigger than search->val
        // Ex: [3,5,1], insertVal = 4 => [3,4,5,1]
        if(insertVal <= search->next->val && insertVal >= search->val) break;
        
        // Case 3: Add to the end of linked list if node* search reaches the end.
        // Ex: [1], insertVal = 2 => [1,2] or // Ex: [3,3,3,3,3,3], insertVal = 4 => [3,3,3,3,3,3,4]
        search = search -> next;
      }
      
      // After checking, add "insertVal" node next to node* search
      Node* temp = search->next;
      search->next = new Node(insertVal);
      search->next->next = temp;
      return head;  
    }
};
