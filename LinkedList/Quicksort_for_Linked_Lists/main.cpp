// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends

typedef struct node node;
 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

node *partition(node *&front, node *&rear) {
    node *temp, *output = front;
    if (front == rear)
        return front;
    int pivot = front->data;
    node **curr = &(front->next);
    while (*curr != rear->next) {
        if ((*curr)->data < pivot) {
            temp = *curr;
            if (*curr == rear) {
                node *temp_rear=output;
                while(temp_rear->next!=temp)
                    temp_rear=temp_rear->next;
                rear =temp_rear;
            }
            *curr = (*curr)->next;
            push(&front, temp->data);
            free(temp);
            temp = nullptr;
            continue;
        }
        curr = &((*curr)->next);
    }

    return output;
}

void _quickSort(node *&front, node *&rear) {
    node *middle = partition(front, rear);

    if (middle != front) {
        // curr = middle->prev
        node *curr = front;
        while (curr->next != middle)
            curr = curr->next;
        _quickSort(front, curr);
    }

    if (middle != rear)
        _quickSort(middle->next, rear);
}

//you have to complete this function
void quickSort(struct node **headRef) {
    if ((*headRef)->next == nullptr)
        return;
    node *back = *headRef;
    while (back->next != nullptr)
        back = back->next;

    _quickSort(*headRef, back);
}