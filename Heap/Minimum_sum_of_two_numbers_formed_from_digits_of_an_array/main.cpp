// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        string a,b,ans="";
        if(n&1)
            b="0";
        sort(arr,arr+n);
        for(int i=0;i<n;i+=2){
            a.push_back(arr[i]+'0');
            if(i==n-1)
                continue;
            b.push_back(arr[i+1]+'0');
                
        }
        int carry=0;
        for(int i=a.length()-1;i>=0;i--){
            int x = a[i]-'0', y= b[i]-'0';
            int sum = x+y+carry;
            carry = sum/10;
            ans+=(sum%10)+'0';
        }
        if(carry)
            ans+= carry+'0';
        while(ans[ans.length()-1]=='0' && ans.length()>1)
            ans.pop_back();
        return string(ans.rbegin(),ans.rend());
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends