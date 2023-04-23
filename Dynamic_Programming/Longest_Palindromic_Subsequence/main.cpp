//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        if(A.length() == 1) return 1;
        if(A.length() == 2) return (A[0] == A[1]) + 1;
        vector<vector<int>> dp(A.length(), vector<int>(A.length(), 0));
        for(int i = 1; i <= A.length(); i++) {
            for(int j = 0; j <= A.length() - i; j++) {
                int k = i + j - 1;
                if(i == 1) {
                    dp[j][k] = 1;
                    continue;
                }
                if(A[j] == A[k]) dp[j][k] = dp[j + 1][k - 1] + 2;
                else dp[j][k] = max(dp[j + 1][k], dp[j][k - 1]);
            }
        }
        return dp[0][A.length() - 1];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends