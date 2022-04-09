/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
  
private:
  void connectTwoNodes(Node *l, Node *r) {
    if (!l || !r) {
      return;
    }
    l->next = r;
    connectTwoNodes(l->left, l->right);
    connectTwoNodes(r->left, r->right);
    connectTwoNodes(l->right, r->left);
  }
  
public:
    Node* connect(Node* root) {
      if (!root) {
        return root;
      }
      connectTwoNodes(root->left, root->right);
      return root;
    }
};
