#include<iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

ListNode *head = nullptr;
Solution sol;

void push(ListNode *head, int data) {
    ListNode node(data);
    if(head == nullptr) {
        head = &node;
        return;
    }
    head->next = &node;
}

void printList(ListNode *p) {
    while(p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << "\n";
}

int main() {
    int n, data;
    ListNode *p = head;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        push(p, data);
    }
    p = sol.middleNode(head);
    printList(p);
    return 0;
}