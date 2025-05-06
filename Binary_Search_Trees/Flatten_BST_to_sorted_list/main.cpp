#include <bits/stdc++.h>
using namespace std;
 
// Node of the binary tree
struct node {
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node *root = nullptr;

// Function to print flattened
// binary Tree
void print(node* parent)
{
    node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}
 
// Function to perform in-order traversal
// recursively
void inorder(node* curr, node*& prev)
{
    // Base case
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}
 
// Function to flatten binary tree using
// level order traversal
node* flatten(node* parent)
{
    // Dummy node
    node* dummy = new node(-1);
 
    // Pointer to previous element
    node* prev = dummy;
 
    // Calling in-order traversal
    inorder(parent, prev);
 
    prev->left = NULL;
    prev->right = NULL;
    node* ret = dummy->right;
 
    // Delete dummy node
    delete dummy;
    return ret;
}

int main() {
    bool toggle = false;
    int n, data;
    node *p = root;
    node *temp = root;
    cin >> n;
    while(n) {
        if(n) {
            cin >> data;
            p->left = new node(data);
            --n;
        }
        if(n) {
            cin >> data;
            p->right = new node(data);
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
    print(flatten(root));
    free(p); free(root);
    return 0;
}