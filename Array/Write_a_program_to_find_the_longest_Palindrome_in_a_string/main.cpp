// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int f=0,e=1;
        int l,h;
        for(int i=1;i<s.size();i++){
            l=i-1;h=i;
            while(l>=0 && h<s.size() && s[l]==s[h]){
                if(h-l+1>e){
                    f=l;
                    e=h-l+1;
                }
                l--;h++;
            }
            l=i-1;h=i+1;
            while(l>=0 && h<s.size() && s[l]==s[h]){
                if(h-l+1>e){
                    f=l;
                    e=h-l+1;
                }
                l--;h++;
            }
        }
        string t="";
        for(int i=f;i<=f+e-1;i++){
            t=t+s[i];
        }
        return t;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
