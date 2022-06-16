// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int dx[4]={-1,1,0,0};
	    int dy[4]={0,0,1,-1};
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                
	                grid[i][j]=0;
	                q.push({i,j});
	                vis[i][j]=1;
	            }
	        }
	    }
	    while(!q.empty())
	    {
	        int s=q.size();
	        while(s--)
	        {
	            auto pr=q.front();
	            q.pop();
	            int x=pr.first;
	            int y=pr.second;
	            for(int i=0;i<4;i++)
	            {
	                
	                if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m && vis[x+dx[i]][y+dy[i]]!=1)
	                {
	                    //cout<<x+dx[i]<<"-"<<y+dy[i]<<endl;
	                    grid[x+dx[i]][y+dy[i]]=1+grid[x][y];
	                    vis[x+dx[i]][y+dy[i]]=1;
	                    q.push({x+dx[i],y+dy[i]});
	                }
	            }
	            
	        }
	        
	    }
	    return grid;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends