// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    void swap(long long *xp, long long *yp) {
        long long temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    long long min(long long a, long long b) {
        return (a <= b) ? a : b;
    }
    long long max(long long a, long long b) {
        return (a >= b) ? a : b;
    }
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long ans = arr[0], min_prod = arr[0], max_prod = arr[0];
	    for(int i = 1; i < n; i++) {
	        if(arr[i] < 0) swap(&min_prod, &max_prod);
	        min_prod = min(arr[i] * min_prod, arr[i]);
	        max_prod = max(arr[i] * max_prod, arr[i]);
	        ans = max(ans, max_prod);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
