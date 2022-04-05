// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    int **dp;
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n == 0) return 0;
        if(n == 1) return arr[0];
        dp = (int **)malloc(n * sizeof(int *));
        for(int i = 0; i < n; i++) {
            dp[i] = (int *)malloc(2 * sizeof(int));
            for(int j = 0; j < 2; j++)
                dp[i][j] = 0;
        }
        dp[0][0] = arr[0];
        dp[1][0] = 0;
        for(int i = 1; i < n; i++) {
            dp[0][i] = arr[i] + dp[1][i - 1];
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
        }
        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];

		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
