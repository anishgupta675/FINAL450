// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string a, string b) {
        // Code here
        int m=a.size(),n=b.size();
        vector<int> f(n+1),s(n+1);
        for(int i=0;i<=n;i++) f[i]=i;
        for(int i=1;i<=m;i++){
            s[0]=i;
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]) s[j]=f[j-1];
                else s[j]=1+min(min(f[j-1],f[j]),s[j-1]);
            }
            f=s;
        }
        return f[n];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
