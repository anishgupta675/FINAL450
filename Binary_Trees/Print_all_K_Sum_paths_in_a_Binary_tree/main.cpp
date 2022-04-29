#include <bits/stdc++.h>
using namespace std;
 
// utility function to print contents of
// a vector from index i to it's end
void printVector(const vector<int>& v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}
 
// binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *root = nullptr;

// This function prints all paths that have sum k
void printKPathUtil(Node* root, vector<int>& path, int k)
{
    // empty node
    if (!root)
        return;
 
    // add current node to the path
    path.push_back(root->data);
 
    // check if there's any k sum path
    // in the left sub-tree.
    printKPathUtil(root->left, path, k);
 
    // check if there's any k sum path
    // in the right sub-tree.
    printKPathUtil(root->right, path, k);
 
    // check if there's any k sum path that
    // terminates at this node
    // Traverse the entire path as
    // there can be negative elements too
    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--) {
        f += path[j];
 
        // If path sum is k, print the path
        if (f == k)
            printVector(path, j);
    }
 
    // Remove the current element from the path
    path.pop_back();
}
 
// A wrapper over printKPathUtil()
void printKPath(Node* root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}

int main() {
    bool toggle = false;
    int n, data, k;
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
    cin >> k;
    printKPath(root, k);
    return 0;
}