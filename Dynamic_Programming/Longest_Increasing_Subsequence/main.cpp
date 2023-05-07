//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    int lower_bound(vector<int> &a, int low, int high, int target) {
        if(low > high) return low;
        int mid = (low + high) >> 1;
        if(target <= a[mid]) return lower_bound(a, low, mid - 1, target);
        return lower_bound(a, mid + 1, high, target);
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int count = 1;
       vector<int> res;
       res.push_back(a[0]);
       for(int i = 1; i < n; i++) {
           if(a[i] > res.back()) {
               res.push_back(a[i]);
               count++;
           } else res[lower_bound(res, 0, res.size() - 1, a[i])] = a[i];
       }
       return res.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends