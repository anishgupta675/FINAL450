// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Node {
public:
    int data;
    Node *prev, *next;
    Node(int data, Node* prev = nullptr, Node* next = nullptr) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
    ~Node() { }
};

class LinkedList {
public:
    Node *head, *tail;
    Node* append(int data) {
        if (head == nullptr)
            head = tail = new Node(data);
        else {
            tail->next = new Node(data, tail);
            tail = tail->next;
        }
        return tail;
    }
    void erase(Node* node) {
        if (node->prev)
            node->prev->next = node->next;
        else
            head = node->next;
        if (node->next)
            node->next->prev = node->prev;
        else
            tail = node->prev;
        delete(node);
    }
    LinkedList() {
        this->head = this->tail = nullptr;
    }
};

class Solution{
public:
    LinkedList List;
    unordered_map<int, Node*> M;
    int pageFaults(int N, int C, int pages[]){
        // code here
        int result = N;
        for (int i = 0; i < N; i++) {
            if (M.find(pages[i]) != M.end()) {
                result--;
                List.erase(M[pages[i]]);
                M.erase(pages[i]);
            }
            if (M.size() == C) {
                M.erase(List.head->data);
                List.erase(List.head);
            }
            M[pages[i]] = List.append(pages[i]);
        }
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends