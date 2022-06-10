#include<bits/stdc++.h>
using namespace std;
 
// using std::stack for
// stack implementation
stack<char> st;
 
// initializing a string to store
// result of reversed stack
string ns;
 
// Below is a recursive function
// that inserts an element
// at the bottom of a stack.
void insert_at_bottom(char x)
{
 
    if(st.size() == 0)
    st.push(x);
 
    else
    {
         
        // All items are held in Function Call
        // Stack until we reach end of the stack
        // When the stack becomes empty, the
        // st.size() becomes 0, the above if
        // part is executed and the item is
        // inserted at the bottom
             
        char a = st.top();
        st.pop();
        insert_at_bottom(x);
 
        // push allthe items held in
        // Function Call Stack
        // once the item is inserted
        // at the bottom
        st.push(a);
    }
}
 
// Below is the function that
// reverses the given stack using
// insert_at_bottom()
void reverse()
{
    if(st.size()>0)
    {
         
        // Hold all items in Function
        // Call Stack until we
        // reach end of the stack
        char x = st.top();
        st.pop();
        reverse();
         
        // Insert all the items held
        // in Function Call Stack
        // one by one from the bottom
        // to top. Every item is
        // inserted at the bottom
        insert_at_bottom(x);
    }
}

int main() {
    char data;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        st.push(data);
    }
    reverse();
    while(!st.empty()) {
        char p = st.top();
        st.pop();
        ns+= p;
    }

    for(int i = ns.length() - 1; i >= 0; i++)
        cout << ns[i];
    
    return 0;
}