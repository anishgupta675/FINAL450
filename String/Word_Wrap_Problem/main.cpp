// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>arr, int m)
    {
        // Code here
        int n=arr.size();
        int a[n+1];
        for(int i=1;i<=n;i++)
            a[i]=arr[i-1];
        int space[n+1][n+1];
        int ls[n+1][n+1];
        int c[n+1];
        for(int i=1;i<=n;i++){
            space[i][i]=m-a[i];
            for(int j=i+1;j<=n;j++){
                space[i][j]=space[i][j-1]-a[j]-1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(space[i][j]<0)
                    ls[i][j]=INT_MAX;
                else if(j==n && space[i][j]>=0)
                    ls[i][j]=0;
                else
                    ls[i][j]=space[i][j]*space[i][j];
            }
        }
        c[0]=0;
        for(int i=1;i<=n;i++){
            c[i]=INT_MAX;
            for(int j=1;j<=i;j++){
                if(c[j-1]!=INT_MAX && ls[j][i]!=INT_MAX && c[j-1]+ls[j][i]<c[i])
                    c[i]=c[j-1]+ls[j][i];
            }
        }
        return c[n];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends
