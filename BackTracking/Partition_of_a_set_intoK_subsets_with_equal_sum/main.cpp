// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool solve(int sum,int n,vector<int>& vis,int csum,int a[],int k)
    {
        if(k==1)
        {
            return true;
        }
        if(csum>sum)return false;
        if(csum==sum)
        {
            return solve(sum,n,vis,0,a,k-1);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                if(solve(sum,n,vis,csum+a[i],a,k))return true;
                vis[i]=0;
            }
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum=accumulate(a,a+n,0);
         if(k>n || sum%k!=0)return false;
         vector<int> vis(n,0);
         sum/=k;
         return solve(sum,n,vis,0,a,k);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends