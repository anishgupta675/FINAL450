// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int ar[2];
    int *findTwoElement(int *arr, int n) {
        // code here
        int a[n+1]={0};
        for(int i=0;i<n;i++){
            a[*arr]++;arr++;
        }

        int m=0,nn=0;
        for(int i=1;i<n+1;i++){
            if(a[i]==0 && m==0){ar[1]=i;m++;}
            if(a[i]>1 ){ar[0]=i;nn++;}
        }
        return ar;
    }
};
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
