// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    stack<char>st;
    int ans=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty())
            {
                st.push(s[i]);
                ans++;
            }
            else
            {
                st.pop();
            }
        }
    }
    if(st.size()%2==0){
        ans+=st.size()/2;
        return ans;
    }
    else
    return -1;
}
