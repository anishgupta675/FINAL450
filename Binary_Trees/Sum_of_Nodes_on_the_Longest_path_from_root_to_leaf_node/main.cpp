// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        if(root==NULL){
            return 0;
        }
        //mapping node with sum upto that node
        map<Node*,pair<int,int>>m;
        queue<pair<pair<Node*,int>,int>>q;
        q.push(make_pair(make_pair(root,root->data),0));
        
        while(!q.empty()){
            pair<pair<Node*,int>,int>temp=q.front();
            q.pop();
            Node* frontnode=temp.first.first;
            int SumUptoNode=temp.first.second;
            int lv=temp.second;
            
            m[frontnode]=make_pair(SumUptoNode,lv);
            
            if(frontnode->left){
            q.push(make_pair(make_pair(frontnode->left,frontnode->left->data+m[frontnode].first),lv+1));
            }
            if(frontnode->right){
            q.push(make_pair(make_pair(frontnode->right,frontnode->right->data+m[frontnode].first),lv+1));
            }
            
        }
        int ans=INT_MIN;
        vector<int>possible;
        int myanslv=-1;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second.second>=myanslv){
                myanslv=it->second.second;
            }
           
        }
        
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second.second==myanslv){
                possible.push_back(it->second.first);
            }
        }
        
        for(int i=0;i<possible.size();i++){
            if(possible[i]>ans){
                ans=possible[i];
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}  // } Driver Code Ends