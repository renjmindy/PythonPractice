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

// APPROACH : BFS W/ O(1) Space

//This problem is similar to LeetCode 116. Populating Next Right Pointers in Each Node, except here at everynode we need to check if it's left & right children exist or not.

//If root->left & root->right exist, then root->left->next is simpy root->right

//But if root->right doesn't exist, root->left->next will be root->next->left or root->next->right or if these both don't exist, root->left->next is simply NULL.

//If root->next exists then root->right->next will be root->next->left or root->next->right or if these both don't exist, it's simply NULL.

class Solution {
  
private:
  Node *find(Node *root){
    if(!root) {
      return nullptr;
    }
    if(root->left) {
      return root->left;
    }
    if(root->right) {
      return root->right;
    }
        
    return find(root->next);
  }
  
public:
  Node* connect(Node* root) {
    if (!root) {
      return nullptr;
    }
    if (root->left) {
      root->left->next = root->right ? root->right : find(root->next);
    }
    if (root->right) {
      root->right->next = find(root->next);
    }
    connect(root->right);
    connect(root->left);
        
    return root;
  }
};
