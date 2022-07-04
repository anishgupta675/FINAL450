#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>&adj,int n,int node,vector<int> &vis){
        
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
            dfs(adj,n,it,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges < n-1) return -1;
    
        vector<vector<int>> adj(n);
    
        for(auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int cnt=-1;
        
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,n,i,vis);
                
            }
        }
        return cnt;
    }
};

vector<vector<int>> connections;
Solution sol;

int main() {
    int n, m, datum;
    vector<int> data;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> datum;
            data.push_back(datum);
        }
        connections.push_back(data);
    }
    cout << sol.makeConnected(n, connections) << endl;
    return 0;
}