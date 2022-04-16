// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node*l,Node*r){
        Node* newList = new Node(-1);
        Node* ans = newList;
        while(l!=nullptr && r!=nullptr){
            if(l->data<r->data){
                    ans->next = new Node(l->data);
                    ans = ans->next;
                    l = l->next;
            }else{
                 ans->next = new Node(r->data);
                    ans = ans->next;
                    r= r->next;
            }
        }
        
        while(l!=nullptr){
          ans->next = new Node(l->data);
                    ans = ans->next;
                    l = l->next;
        }
         while(r!=nullptr){
            ans->next = new Node(r->data);
                    ans = ans->next;
                    r= r->next;
        }
        return newList->next;
    }
    
    
    Node* mergeSort(Node* head) {
      Node* ans = head;
        if(head->next!=nullptr){
            
            Node* mid  = getMid(head);
            Node* right  = mid->next;
            mid->next = nullptr;
            Node* l = mergeSort(head);
            Node* r = mergeSort(right);
            ans =  merge(l,r);
           
        }
        
        return ans;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends