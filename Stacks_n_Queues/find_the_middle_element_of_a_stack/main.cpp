#include <bits/stdc++.h>
using namespace std;
 
class myStack {
    struct Node {
        int num;
        Node* next;
        Node* prev;
 
        Node(int num) { this->num = num; }
    };
 
    // Members of stack
    Node* head = NULL;
    Node* mid = NULL;
    int size = 0;
 
public:
    void push(int data)
    {
        Node* temp = new Node(data);
        if (size == 0) {
            head = temp;
            mid = temp;
            size++;
            return;
        }
 
        head->next = temp;
        temp->prev = head;
 
        // update the pointers
        head = head->next;
        if (size % 2 == 1) {
            mid = mid->next;
        }
        size++;
    }
 
    int pop()
    {
      int data=-1;
        if (size != 0) {
          data=head->num;
            if (size == 1) {
                head = NULL;
                mid = NULL;
            }
            else {
                head = head->prev;
                head->next = NULL;
                if (size % 2 == 0) {
                    mid = mid->prev;
                }
            }
            size--;
        }
      return data;
    }
 
    int findMiddle()
    {
        if (size == 0) {
            return -1;
        }
        return mid->num;
    }
 
    void deleteMiddle()
    {
        if (size != 0) {
            if (size == 1) {
                head = NULL;
                mid = NULL;
            }
            else if (size == 2) {
                head = head->prev;
                mid = mid->prev;
                head->next = NULL;
            }
            else {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0) {
                    mid = mid->prev;
                }
                else {
                    mid = mid->next;
                }
            }
            size--;
        }
    }
};

myStack st;

int main() {
    int n, data;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        st.push(data);
    }
    cout << st.findMiddle() << endl;
    st.deleteMiddle();
    cin >> n;
    for(int i = 0; i < n - 1; i++)
        cout << st.pop() << endl;
    cout << st.findMiddle() << endl;
    return 0;
}