//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int MOD = 1000000007;

class Solution{
    long long int dp[1001][1001];
    long long int countPS(string str, int i, int j) {
        if(i > j) return 0;
        if(dp[i][j]) return dp[i][j];
        if(i == j) return dp[i][j] = 1;
        if(str[i] == str[j]) return dp[i][j] = (1 + (countPS(str, i + 1, j) % MOD) + (countPS(str, i, j - 1) % MOD)) % MOD;
        return dp[i][j] = (MOD + (countPS(str, i + 1, j) % MOD) + (countPS(str, i, j - 1) % MOD) - (countPS(str, i + 1, j - 1) % MOD)) % MOD;
    }
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       // fill(&dp[0][0], &dp[0][0] + sizeof(dp), 0);
       for(int i = 0; i < str.length(); i++) for(int j = 0; j < str.length(); j++) dp[i][j] = 0;
       return countPS(str, 0, str.length() - 1);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends