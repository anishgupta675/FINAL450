// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
    cout<<"\n";
}


 // } Driver Code Ends
//User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node* reverse(Node * head){
        Node* r=NULL,*q=NULL,*p=head;
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    public:
    Node* addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        head=reverse(head);
        Node* p=head;
        Node * prev=head;
        while(p){
            if(p->data<9){
                p->data+=1;
                break;
            }
            else{
                p->data=0;
                prev=p;
                p=p->next;
            }
        }
        if(p==NULL){
            Node* temp=new Node(1);
            prev->next=temp;
        }
        return reverse(head);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
  // } Driver Code Ends
