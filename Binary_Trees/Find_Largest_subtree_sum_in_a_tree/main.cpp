#include <bits/stdc++.h>
using namespace std;
 
// Structure of a tree node.
struct Node {
    int key;
    Node *left, *right;
};

Node *root = nullptr;

// Function to create new tree node.
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Helper function to find largest
// subtree sum recursively.
int findLargestSubtreeSumUtil(Node* root, int& ans)
{
    // If current node is null then
    // return 0 to parent node.
    if (root == NULL)    
        return 0;
     
    // Subtree sum rooted at current node.
    int currSum = root->key +
      findLargestSubtreeSumUtil(root->left, ans)
      + findLargestSubtreeSumUtil(root->right, ans);
 
    // Update answer if current subtree
    // sum is greater than answer so far.
    ans = max(ans, currSum);
 
    // Return current subtree sum to
    // its parent node.
    return currSum;
}
 
// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root)
{
    // If tree does not exist,
    // then answer is 0.
    if (root == NULL)    
        return 0;
     
    // Variable to store maximum subtree sum.
    int ans = INT_MIN;
 
    // Call to recursive function to
    // find maximum subtree sum.
    findLargestSubtreeSumUtil(root, ans);
 
    return ans;
}

int main() {
    bool toggle = false;
    int n, data;
    cin >> n >> data;
    root = newNode(data);
    for(int i = 1; i < n; i++) {
        cin >> data;
        if(i % 2) root->left = newNode(data);
        else root->right = newNode(data);
        Node *temp = root;
        if(toggle) root = temp->left;
        else root = temp->right;
    }
    cout << findLargestSubtreeSum(root) << endl;
    free(root);
    return 0;
}