// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int recursion(int i,int j,string &str,vector<vector<int>> &dp){
            if(i==str.length() || j==str.length()){
                return 0;
            }
            else if(dp[i][j]!=-1){
                return dp[i][j];
            }
            else if(str[i]==str[j] && i!=j){
                return dp[i][j]=1+recursion(i+1,j+1,str,dp);
            }
            else{
                return dp[i][j]=max(recursion(i,j+1,str,dp),recursion(i+1,j,str,dp));
            }
        }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    vector<vector<int>> dp(str.length(),vector<int>(str.length(),-1));
            int answer=recursion(0,0,str,dp);
            return answer;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
