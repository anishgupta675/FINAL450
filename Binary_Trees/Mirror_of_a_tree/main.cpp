#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode *oldLeft = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(oldLeft);
        return root;
    }
};
TreeNode *root = nullptr;
Solution sol;
void display(TreeNode *root) {
    if(!root) return;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *t = q.front();
        q.pop();
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
        cout << t->val << " ";
    }
    cout << "\n";
}
int main() {
    bool toggle = false;
    int n, data;
    TreeNode *p = root;
    TreeNode *temp = root;
    cin >> n;
    while(n) {
        if(n) {
            cin >> data;
            TreeNode left_subtree(data);
            p->left = &left_subtree;
            --n;
        }
        if(n) {
            cin >> data;
            TreeNode right_subtree(data);
            p->right = &right_subtree;
            --n;
        }
        temp = p;
        if(toggle) {
            p = temp->left;
            toggle = false;
        } else {
            p = temp->right;
            toggle = true;
        }
        free(temp);
    }
    p = sol.invertTree(root);
    display(p);
    free(p); free(root);
    return 0;
}