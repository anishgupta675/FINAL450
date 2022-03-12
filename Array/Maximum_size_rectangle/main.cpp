// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int getm(vector<int> a){
        int ans=0;
        a.push_back(-1);
        int n=a.size();
        int i=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>a[i]){
                int t=st.top();
                st.pop();
                int cu=a[t]*(st.empty() ? i : (i-st.top()-1));
                ans=max(ans,cu);
            }
            st.push(i);
        }

        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> a(m);
        for(int i=0;i<m;i++){
            a[i]=M[0][i];
        }
        int ans=getm(a);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==1) a[j]++;
                else a[j]=0;
            }
            ans=max(ans,getm(a));
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
