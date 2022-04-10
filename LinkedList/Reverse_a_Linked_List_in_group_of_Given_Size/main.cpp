// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    {
        // Complete this method
        if(head == nullptr || k == 1) return head;
        struct node *prev = nullptr, *curr = head, *after = nullptr;
        int i = 1;
        while(curr != nullptr && i <= k) {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
            i++;
        }
        struct node *prev_start = head, *start = curr;
        head = prev;
        prev = nullptr;
        i = 1;
        while(curr != nullptr) {
            if(i == k || curr->next == nullptr) {
                prev_start->next = curr;
                after = curr->next;
                curr->next = prev;
                prev = nullptr;
                curr = after;
                i = 1;
                prev_start = start;
                start = curr;
            } else {
                after = curr->next;
                curr->next = prev;
                prev = curr;
                curr = after;
                i++;
            }
        }
        return head;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;

    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;

        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin>>k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return(0);
}

  // } Driver Code Ends
