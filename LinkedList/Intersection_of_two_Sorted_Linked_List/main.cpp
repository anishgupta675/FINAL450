// { Driver Code Starts
//

#include<iostream>
#include<map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
   Node* first = head1;
   Node* second = head2;
   Node* dummy = new Node(-1);
   Node* ans = dummy;
   
   map<int, bool>visited;
   while(first != NULL){
       visited[first->data] = true;
       first = first->next;
   }
   
   while(second != NULL){
       if(visited[second->data] == true){
           Node* temp = new Node(second->data);
           ans->next = temp;
           ans = temp;
           visited[second->data] = false;
       }
       
       second = second->next;
   }
   
   return dummy->next;
}