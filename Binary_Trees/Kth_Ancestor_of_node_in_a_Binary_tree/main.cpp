#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

Node *root = nullptr;

// temporary node to keep track of Node returned
// from previous recursive call during backtrack
Node* temp = NULL;
 
// recursive function to calculate Kth ancestor
Node* kthAncestorDFS(Node *root, int node , int &k)
{  
    // Base case
    if (!root)
        return NULL;
     
    if (root->data == node||
       (temp =  kthAncestorDFS(root->left,node,k)) ||
       (temp =  kthAncestorDFS(root->right,node,k)))
    {  
        if (k > 0)       
            k--;
         
        else if (k == 0)
        {
            // print the kth ancestor
            cout<<"Kth ancestor is: "<<root->data;
             
            // return NULL to stop further backtracking
            return NULL;
        }
         
        // return current node to previous call
        return root;
    }
    return nullptr;
}
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main() {
    bool toggle = false;
    int n, data, k, node;
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
    cin >> k >> node;
    if(kthAncestorDFS(root, node, k)) cout << "-1";
    free(root);
    return 0;
}