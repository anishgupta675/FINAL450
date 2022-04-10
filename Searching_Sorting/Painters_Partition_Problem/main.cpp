// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    int getSum(int *A, int N) {
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum+= A[i];
        return sum;
    }
    bool findPagesUtil(int *A, int N, int M, int MID) {
        int i = 0, part_sum = 0, cntr = 0;
        while(i < N) {
            if(A[i] > MID) return false;
            if((part_sum + A[i]) > MID) {
                cntr++;
                part_sum = A[i];
                if(cntr >= M) return false;
            } else part_sum+= A[i];
            i++;
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    {
        //code here
        int right = getSum(A, N), ans = right, left = 1;
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            if(findPagesUtil(A, N, M, mid)) {
                right = mid - 1;
                ans = mid;
            } else left = mid + 1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
