#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *head = nullptr;

ListNode *newNode(int key) {
    ListNode *temp = new ListNode(key);
    return temp;
}

ListNode* detectCycle(ListNode* A)
{

    // declaring map to store node address
    unordered_set<ListNode*> uset;

    ListNode *ptr = A;

    // Default consider that no cycle is present
    while (ptr != NULL) {

        // checking if address is already present in map
        if (uset.find(ptr) != uset.end())
          return ptr;

        // if address not present then insert into the set
        else
            uset.insert(ptr);

        ptr = ptr->next;
    }
    return NULL;
}

int main() {
    int n, data;
    ListNode *p = head;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        p = newNode(data);
        p = p->next;
    }

    // p->next = head;
    p = head;

    p = detectCycle(head);
    if(p == NULL) cout << "Loop does not exist";
    else cout << "Loop starting node is " << p->val;

    return 0;
}
