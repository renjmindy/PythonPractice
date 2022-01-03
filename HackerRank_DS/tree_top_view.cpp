#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        queue<pair<int, Node*> > q;
        q.push(make_pair(0, root));
        map<int, Node*> mp;
        //int hd = 0;
        //root->data = hd;
        for (auto i = q.front(); !q.empty(); q.pop(), i = q.front()) {
            if (!i.second) continue;
            mp.insert(i);
            q.push(make_pair(i.first + 1, i.second->right));
            q.push(make_pair(i.first - 1, i.second->left));
        }
        /*while (q.size()) {
            hd = root->data;
            if (mp.count(hd) == 0) {
                mp[hd] = root;
            }
            if (root->left) {
                root->left->data = hd - 1;
                q.push(make_pair(q.front().first - 1, q.front().second->left));
            }
            if (root->right) {
                root->right->data = hd + 1;
                q.push(make_pair(q.front().first + 1, q.front().second->right));
            }
            q.pop();
            root = q.front().second;
        }*/
        /*while (!q.empty()) {
            if (!q.front().second) continue;
            //hd = root->data;
            //if (mp.count(hd) == 0) {
            mp.insert(q.front());
            //}
            //if (root->left) {
                //root->left->data = hd - 1;
                q.push(make_pair(q.front().first - 1, q.front().second->left));
            //}
            //if (root->right) {
                //root->right->data = hd + 1;
                q.push(make_pair(q.front().first + 1, q.front().second->right));
            //}
            q.pop();
            //root = q.front().second;
        }*/
        for (auto m : mp) {
            cout << m.second->data << " ";
        }
    }

}; //End of Solution
