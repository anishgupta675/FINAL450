// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> ans;
    bool flag;

    bool isValid(int x,int y,int n,int m){
        if(x < 0 || x >= n || y < 0 || y >= m) return (false);
        return (true);
    }

    void helper(vector<vector<char>> &grid,int x,int y,string word,int i,int sti,int stj,int dir){
        if(i == word.length()-1){
            ans.push_back({sti,stj});
            flag = true;
            return;
        }

        int dx[] = {-1,-1,0,1,1,1,0,-1};
        int dy[] = {0,1,1,1,0,-1,-1,-1};

        int new_x = x + dx[dir];
        int new_y = y + dy[dir];

        if(isValid(new_x,new_y,grid.size(),grid[0].size()) && grid[new_x][new_y] == word[i+1]){
            helper(grid,new_x,new_y,word,i+1,sti,stj,dir);
        }
    }

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == word[0]){
                    if(word.length() > 1){
                        int dx[] = {-1,-1,0,1,1,1,0,-1};
                        int dy[] = {0,1,1,1,0,-1,-1,-1};

                        for(int k=0; k<8; k++){
                            int new_x = i + dx[k];
                            int new_y = j + dy[k];
                            if(isValid(new_x,new_y,n,m) && grid[new_x][new_y] == word[1]){
                                flag = false;
                                helper(grid,new_x,new_y,word,1,i,j,k);
                                if(flag){
                                    break;
                                }
                            }
                        }
                    }
                    else{
                        ans.push_back({i,j});
                    }
                }
            }
        }

        return (ans);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends
