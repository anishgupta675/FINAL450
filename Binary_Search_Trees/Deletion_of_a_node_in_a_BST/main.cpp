#include<bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode() {
        this->val = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int x) {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) {
        this->val = x;
        this->left = left;
        this->right = right;
    }
    TreeNode *Insert(TreeNode *root, int value) {
        if (!root) {
            // Insert the first node, if root is NULL.
            return new TreeNode(value);
        }
 
        // Insert data.
        if (value > root->val) {
            // Insert right node data, if the 'value'
            // to be inserted is greater than 'root' node data.
 
            // Process right nodes.
            root->right = Insert(root->right, value);
        }
        else {
            // Insert left node data, if the 'value'
            // to be inserted is greater than 'root' node data.
 
            // Process left nodes.
            root->left = Insert(root->left, value);
        }
 
        // Return 'root' node, after insertion.
        return root;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        
        if (root->val == key) {
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;
            TreeNode* right = root->right;
            while (right->left)
                right = right->left;
            right->left = root->left;
            return root->right;
        }
        
        TreeNode* left = deleteNode(root->left, key);
        TreeNode* right = deleteNode(root->right, key);
        root->left = left;
        root->right = right;
        return root;
    }
};

TreeNode b, *root = nullptr;
Solution sol;

int main() {
    int n, data, key;
    cin >> n >> data;
    root = b.Insert(root, data);
    for(int i = 1; i < n; i++) {
        cin >> data;
        b.Insert(root, data);
    }

    cin >> key;

    sol.deleteNode(&b, key);
    free(root);
    return 0;
}