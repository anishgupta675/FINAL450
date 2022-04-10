#include <iostream>
#include<cstdlib>
using namespace std;

typedef struct node
{
  int val;
  struct node* next;
}node;

node* head=NULL;

int count(node* head) // code to count the no. of nodes
{
  node* p=head;
  int k=1;
  while(p!=NULL)
  {
    p=p->next;
    k++;
  }
  return k;
}

node *ll_reverse(node* head)  // to reverse the linked list
{
  node* p=head;
  long int i=count(head),j=1;
  long int arr[i];
  while(i && p!=NULL)
  {
    arr[j++]=p->val;
    p=p->next;
    i--;
  }
  j--;
  while(j) // loop will break as soon as j=0
  {
    cout<<arr[j--]<<" ";
  }

  return head;
}

node* insert_end(node* head,int data)  //code to insert at end of ll
{
  node* q=head,*p=(node*)malloc(sizeof(node));
  p->val=data;
  while(q->next!=NULL)
  {
    q=q->next;
  }
  q->next=p;
  p->next=NULL;
  return head;
}

node *create_ll(node* head,int data)  //create ll
{
  node* p=(node*)malloc(sizeof(node));
  p->val=data;
  if(head==NULL)
  {
    head=p;
    p->next=NULL;
    return head;
  }
  else
  {
    head=insert_end(head,data);
    return head;
  }
}

void printList(node *head) {
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, data;
    cin >> n;
    while(n--) {
        cin >> data;
        head = create_ll(head, data);
    }
    head = ll_reverse(head);
    printList(head);
    free(head);
    return 0;
}
