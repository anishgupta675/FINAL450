// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    char getClosing(char ch) {
        if(ch == '(') return ')';
        if(ch == '{') return '}';
        return ']';
    }
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        stack<char> braces;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') braces.push(s[i]);
            else {
                if(!braces.empty() && s[i] == getClosing(braces.top())) braces.pop();
                else return false;
            }
        }
        return braces.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
