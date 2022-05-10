// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    const long long int MOD = 1e9 + 7;
    unsigned long long int Maximize(int a[],int n)
    {
        // Complete the function
        unsigned long long int sum = 0;
        sort(a, a + n);
        for(unsigned long long int i = 0; i < n; i++)
            sum+= a[i] * i;
        return sum % MOD;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}  // } Driver Code Ends