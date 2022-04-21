class Solution {
  
private:
  int size = 1;
  vector<int> ans;
  void inOrder(Node *root) {
    if (!root) {
      return;
    }
    inOrder(root->left);
    ans.push_back(root->val);
    inOrder(root->right);
  }
  Node* helper(Node* pre) {
    if (size == ans.size()) { // base case
      return pre;
    }
    Node *tmp = new Node(ans[size]);
    pre->right = tmp;
    tmp->left = pre;
    size++;
    
    return helper(tmp);
  }
  
public:
    Node* treeToDoublyList(Node* root) {
      // corner case
      if (!root) {
        return nullptr;
      }
      if (!root->left && !root->right) {
        root->left = root;
        root->right = root;
        return root;
      }
      // vectorize the array with InOrderTraversal of BST
      inOrder(root);
      // create a new doubly linked list
      Node *head = new Node(ans[0]);
      Node *tail = helper(head);
      head->left = tail;
      tail->right = head;
      
      return head;
    }
};
