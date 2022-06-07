#include<bits/stdc++.h>
using namespace std;
 
// A C++ class to represent k stacks in a single array of size n
class kStacks
{
    int *arr;   // Array of size n to store actual content to be stored in stacks
    int *top;   // Array of size k to store indexes of top elements of stacks
    int *next;  // Array of size n to store next entry in all stacks
                // and free list
    int n, k;
    int free; // To store beginning index of free list
public:
    //constructor to create k stacks in an array of size n
    kStacks(int k, int n);
 
    // A utility function to check if there is space available
    bool isFull()   {  return (free == -1);  }
 
    // To push an item in stack number 'sn' where sn is from 0 to k-1
    void push(int item, int sn);
 
    // To pop an from stack number 'sn' where sn is from 0 to k-1
    int pop(int sn);
 
    // To check whether stack number 'sn' is empty or not
    bool isEmpty(int sn)  {  return (top[sn] == -1); }
};
 
//constructor to create k stacks in an array of size n
kStacks::kStacks(int k1, int n1)
{
    // Initialize n and k, and allocate memory for all arrays
    k = k1, n = n1;
    arr = new int[n];
    top = new int[k];
    next = new int[n];
 
    // Initialize all stacks as empty
    for (int i = 0; i < k; i++)
        top[i] = -1;
 
    // Initialize all spaces as free
    free = 0;
    for (int i=0; i<n-1; i++)
        next[i] = i+1;
    next[n-1] = -1;  // -1 is used to indicate end of free list
}
 
// To push an item in stack number 'sn' where sn is from 0 to k-1
void kStacks::push(int item, int sn)
{
    // Overflow check
    if (isFull())
    {
        cout << "\nStack Overflow\n";
        return;
    }
 
    int i = free;      // Store index of first free slot
 
    // Update index of free slot to index of next slot in free list
    free = next[i];
 
    // Update next of top and then top for stack number 'sn'
    next[i] = top[sn];
    top[sn] = i;
 
    // Put the item in array
    arr[i] = item;
}
 
// To pop an from stack number 'sn' where sn is from 0 to k-1
int kStacks::pop(int sn)
{
    // Underflow check
    if (isEmpty(sn))
    {
         cout << "\nStack Underflow\n";
         return INT_MAX;
    }
 
 
    // Find index of top item in stack number 'sn'
    int i = top[sn];
 
    top[sn] = next[i];  // Change top to store next of previous top
 
    // Attach the previous top to the beginning of free list
    next[i] = free;
    free = i;
 
    // Return the previous top item
    return arr[i];
}

int main() {
    int k, n, data;
    cin >> k >> n;
    kStacks ks(k, n);

    for(int i = 0; i < k; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> data;
            ks.push(data, i);
        }
        cout << ks.pop(i) << endl;
    }

    return 0;
}