// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> st;
        int ans = 0;
        int i=0; 
        while(i<s.size())
        {
            if(s[i]=='(') st.push(i);
            else {
                if(!st.empty() && s[st.top()] =='(')
                {  
                    st.pop();
                    int x;
                    if(!st.empty()) {
                        x = st.top();
                    } else x=-1;
                               
                    ans = max(ans, i-x);
                }
                else {
                    st.push(i);
                }
            }
            ++i;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends