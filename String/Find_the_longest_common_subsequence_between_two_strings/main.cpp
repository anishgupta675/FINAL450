// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int dp[s1.length()+1][s2.length()+1];

        for(int x=0;x<=s1.length();x++)
        {
            for(int y=0;y<=s2.length();y++)
            {
                if(x==0||y==0)
                dp[x][y]=0;

                else if(s1[x-1]==s2[y-1])
                {
                    dp[x][y]=1+dp[x-1][y-1];
                }

                else
                {
                    dp[x][y]=max(dp[x][y-1],dp[x-1][y]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
