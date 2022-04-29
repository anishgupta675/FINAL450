#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
class Node {
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node *root = nullptr;
// declare map /dp array as global
unordered_map<Node*, int> umap;
int maxSum(Node* root)
{
    // base case
    if (!root)
        return 0;
 
    // if the max sum from the  node is already in
    // map,return the value
    if (umap[root])
        return umap[root];
 
    // if the current node(root) is included in result
    // then find maximum sum
    int inc = root->data;
 
    // if left of node exists, add their grandchildren
    if (root->left) {
        inc += maxSum(root->left->left)
               + maxSum(root->left->right);
    }
    // if right of node exist,add their grandchildren
    if (root->right) {
        inc += maxSum(root->right->left)
               + maxSum(root->right->right);
    }
 
    // if the current node(root) is excluded, find the
    // maximum sum
    int ex = maxSum(root->left) + maxSum(root->right);
 
    // store the maximum of including & excluding the node
    // in map
    umap[root] = max(inc, ex);
    return max(inc, ex);
}

int main() {
    bool toggle = false;
    int n, data;
    cin >> n >> data;
    root = new Node(data);
    for(int i = 1; i < n; i++) {
        cin >> data;
        if(i % 2) root->left = new Node(data);
        else root->right = new Node(data);
        Node *temp = root;
        if(toggle) root = temp->left;
        else root = temp->right;
    }
    cout << maxSum(root) << endl;
    return 0;
}