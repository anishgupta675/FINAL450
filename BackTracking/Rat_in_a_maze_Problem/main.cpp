// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    char p[4] = {'D','U','R','L'};
    void solve(int x, int y, vector<vector<int>>& m, string s, int n){
        if(x==n-1 && y==n-1){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<4;i++){
            int nx = x+dir[i][0], ny = y+dir[i][1];
            if(nx>=0 && nx<n && ny>=0 && ny<n && m[nx][ny]==1){
                m[x][y] = 0;
                solve(nx,ny,m,s+p[i],n);
                m[x][y] = 1;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        ans.clear();
        if(m[0][0]==1) solve(0,0,m,"",n);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends