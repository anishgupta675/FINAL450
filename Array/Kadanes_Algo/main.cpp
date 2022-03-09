// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    long long max(long long a, long long b) {
        return (a >= b) ? a : b;
    }
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){

        // Your code here
        long long max_sum = arr[0], current_sum = max_sum;
        for(int i = 1; i < n; i++) {
            current_sum = max(arr[i] + current_sum, arr[i]);
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;

    }
};

// { Driver Code Starts.

int main()
{
    int t,n;

    cin>>t; //input testcases
    while(t--) //while testcases exist
    {

        cin>>n; //input size of array

        int a[n];

        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
