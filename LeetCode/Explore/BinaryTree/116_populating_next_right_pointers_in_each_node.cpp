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
  void connect_two_nodes(Node *l, Node *r) {
    // since this is a perfect binary tree, if node_1 is None meaning its parent is terminal leaf
    if (!l || !r) {
      return;
    }
    // r's next either stay pointing to None 
    // or is handled by other call; see the cross parent section below
    l->next = r;
    // same parent
    connect_two_nodes(l->left, l->right);
    connect_two_nodes(r->left, r->right);
    // cross parent
    connect_two_nodes(l->right, r->left);
  }
  
public:
  Node* connect(Node* root) {
    if (!root) {
      return nullptr;
    }
    connect_two_nodes(root->left, root->right);
    return root;
  }
};
