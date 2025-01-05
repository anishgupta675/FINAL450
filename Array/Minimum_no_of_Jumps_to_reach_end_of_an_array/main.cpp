// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int res = 0, low = 0, high = 0;
        while(high < n - 1) {
            int max_jump = 0;
            for(int i = low; i <= high; i++)
                max_jump = max(max_jump, i + arr[i]);
            low = high + 1;
            high = max_jump;
            if(low > high) return -1;
            res++;
        }
        return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
