//{ Driver Code Starts
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
        vector<int> dp(y + 1);
        for(int i = 0; i < x; i++) {
            int prev = dp[0];
            for(int j = 1; j < dp.size(); j++) {
                int temp = dp[j];
                if(s1[i] != s2[j - 1]) dp[j] = max(dp[j], dp[j - 1]);
                else dp[j] = prev + 1;
                prev = temp;
            }
        }
        return dp.back();
    }
};


//{ Driver Code Starts.
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