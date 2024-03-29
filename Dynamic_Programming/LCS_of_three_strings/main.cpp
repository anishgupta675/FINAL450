//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int ***dp = nullptr;

int LCSof3Util(string A, string B, string C, int i, int j, int k) {
    if(i < 0 || j < 0 || k < 0) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(A[i] == B[j] && B[j] == C[k]) return dp[i][j][k] = 1 + LCSof3Util(A, B, C, i - 1, j - 1, k - 1);
    return dp[i][j][k] = max(LCSof3Util(A, B, C, i - 1, j, k), max(LCSof3Util(A, B, C, i, j - 1, k), LCSof3Util(A, B, C, i, j, k - 1)));
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    dp = (int ***)malloc(n1 * sizeof(int **));
    for(int i = 0; i < n1; i++) {
        dp[i] = (int **)malloc(n2 * sizeof(int *));
        for(int j = 0; j < n2; j++) {
            dp[i][j] = (int *)malloc(n3 * sizeof(int));
            for(int k = 0; k < n3; k++) dp[i][j][k] = -1;
        }
    }
    return LCSof3Util(A, B, C, n1 - 1, n2 - 1, n3 - 1);
}