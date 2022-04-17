#include<iostream>
using namespace std;
 
class Node
{
    public:
        char data;
        Node* next;
        Node* pre;
    Node(int data)
    {
        this->data=data;
        pre=NULL;
        next=NULL;
    }
};

Node *head = nullptr;

void insertAtHead(Node* &head, int data)
{
    Node* n = new Node(data);
    if(head==NULL)
    {
        head=n;
        return;
    }
    n->next=head;
    head->pre=n;
    head=n;
    return;
}
void insertAtTail(Node* &head, int data)
{
    if(head==NULL)
    {
        insertAtHead(head,data);
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* n=new Node(data);
    temp->next=n;
    n->pre=temp;
    return;
}
void display(Node* head)
{
    while(head!=NULL)
    {
        cout << head->data << "-->";
        head=head->next;
    }
    cout << "NULL\n";
}
 
void rotateByN(Node *&head, int pos)
{
    if (pos == 0)
        return;
 
    Node *curr = head;
 
    while (pos)
    {
        curr = curr->next;
        pos--;
    }
 
    Node *tail = curr->pre;
    Node *NewHead = curr;
    tail->next = NULL;
    curr->pre = NULL;
 
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
     
    curr->next = head;
    head->pre = curr;
    head = NewHead;
}

int main() {
    char data;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        insertAtTail(head, data);
    }
    cin >> n;
    rotateByN(head, n);
    display(head);
    free(head);
    return 0;
}