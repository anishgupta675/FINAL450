#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int solve(vector<pair<int, int>>adj[], int node, int dest, int k, vector<vector<int>>&dp){
        
        if(node == dest){
            return 0;
        }
        
        if(k == 0){
            return 1e8;
        }
        
        if(dp[node][k]!=-1)
            return dp[node][k];
        
        int mini = 1e8;
        
        for(auto it: adj[node]){
            int price = it.second + solve(adj, it.first, dest, k-1, dp);
            
            mini = min(mini, price);
        }
        
        return dp[node][k] = mini;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int mini = 1e9;
        vector<pair<int, int>>adj[n];
        
        for(int i=0;i<flights.size();i++){
            int a = flights[i][0];
            int b = flights[i][1];
            int wt = flights[i][2];
            
            adj[a].push_back({b, wt});
        }
        
        vector<vector<int>>dp(n, vector<int>(k+2, -1));
        
        int val = solve(adj, src, dst, k+1, dp);
        
        if(val >= 1e8)
            return -1;
        return val;
    }
};

vector<vector<int>> flights;
Solution sol;

int main() {
    int n, src, dst, k, datum;
    vector<int> data;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> datum;
            data.push_back(datum);
        }
        flights.push_back(data);
    }
    cin >> src >> dst >> k;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}