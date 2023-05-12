//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        if(N == 1) return Matrix[0][0];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(i > 0 && j > 0) Matrix[i][j]+= min(Matrix[i - 1][j], Matrix[i][j - 1]);
                else if(i > 0) Matrix[i][j]+= Matrix[i - 1][j];
                else if(j > 0) Matrix[i][j]+= Matrix[i][j - 1];
                else continue;
            }
        }
        return Matrix[N - 1][N - 1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends