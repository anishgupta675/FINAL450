#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node *left, *right;
};

Node *root = nullptr;

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
vector <vector <int>> result;
void diagonalPrint(Node* root)
{
    if(root == NULL)
        return;
 
    queue <Node*> q;
    q.push(root);
 
    while(!q.empty())
    {
        int size = q.size();
        vector <int> answer;
 
        while(size--)
        {
            Node* temp = q.front();
            q.pop();
 
            // traversing each component;
            while(temp)
            {
                answer.push_back(temp->data);
 
                if(temp->left)
                    q.push(temp->left);
 
                temp = temp->right;
            }
        }
        result.push_back(answer);
    }
}

void display(vector<vector<int>> &result) {
    for(int i=0 ; i<result.size() ; i++)
    {
        for(int j=0 ; j<result[i].size() ; j++)
            cout<<result[i][j]<<"  ";
        cout<<endl;
    }
}

int main() {
    bool toggle = false;
    int n, data;
    Node *p = root;
    Node *temp = root;
    cin >> n;
    while(n) {
        if(n) {
            cin >> data;
            p->left = newNode(data);
            --n;
        }
        if(n) {
            cin >> data;
            p->right = newNode(data);
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
    diagonalPrint(root);
    display(result);
    free(p); free(root);
    return 0;
}