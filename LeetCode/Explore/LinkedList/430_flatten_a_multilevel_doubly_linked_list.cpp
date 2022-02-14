/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
  
private:
  Node *flattenDFS(Node *prev, Node *curr) {
    if (!curr) {
      return prev;
    }
    curr->prev = prev;
    prev->next = curr;
    
    Node *tmpNext = curr->next;
    Node *tail = flattenDFS(curr, curr->child);
    curr->child = NULL;
    return flattenDFS(tail, tmpNext);
  }
  
public:
    Node* flatten(Node* head) {
      if (!head) {
        return head;
      }
      Node *pseudoHead = new Node(0, NULL, head, NULL);
      flattenDFS(pseudoHead, head);
      pseudoHead->next->prev = NULL;
      return pseudoHead->next;
    }
};
