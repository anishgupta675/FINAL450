// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,__builtin_popcount(arr[i]));
        }
        vector<int>a[maxi+1];
        for(int i=0;i<n;i++){
            a[__builtin_popcount(arr[i])].push_back(arr[i]);
        }
        int k=0;
        for(int i=maxi;i>=0;i--){
            for(auto val:a[i]){
                arr[k]=val;
                k++;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
