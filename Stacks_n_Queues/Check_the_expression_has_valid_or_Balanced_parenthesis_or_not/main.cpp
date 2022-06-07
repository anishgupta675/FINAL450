// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    private:
    bool isValid(stack<char> &parenthesis, char x) {
        if(parenthesis.top() == '{' && x == '}') return true;
        if(parenthesis.top() == '(' && x == ')') return true;
        if(parenthesis.top() == '[' && x == ']') return true;
        return false;
    }
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        if(x.length() % 2) return false;
        stack<char> parenthesis;
        for(int i = 0; i < x.length(); i++) {
            if(x[i] == '{' || x[i] == '(' || x[i] == '[') parenthesis.push(x[i]);
            else if(x[i] == '}' || x[i] == ')' || x[i] == ']') {
                if(parenthesis.empty()) parenthesis.push(x[i]);
                else if(parenthesis.top() == '}' || parenthesis.top() == ')' || parenthesis.top() == ']') parenthesis.push(x[i]);
                else if(parenthesis.top() == '{' || parenthesis.top() == '(' || parenthesis.top() == '[') {
                    if(!isValid(parenthesis, x[i])) return false;
                    parenthesis.pop();
                }
            }
        }
        return parenthesis.empty();
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