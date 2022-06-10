#include<bits/stdc++.h>

using namespace std;

stack<char> st;

void insert_at_bottom(char x) {
    if(st.empty()) st.push(x);
    else {

        char a = st.top();
        st.pop();
        insert_at_bottom(x);

        st.push(a);
    }
}

int main() {}