#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> count(26,0);
		    string res="";
		    queue<int> q;
		    for(int i=0;i<A.size();i++){
		        count[A[i]-'a']++;
		        bool found = false;
		        while(!q.empty()){
		           if(count[A[q.front()]-'a']>1)q.pop();
		           else{
		              res.push_back(A[q.front()]);
		              found = true;
		              break;
		            }
		          }
		          if(count[A[i]-'a']==1)q.push(i);
		       if(found)continue;
		       if(count[A[i]-'a']==1)res.push_back(A[i]);
		       else res.push_back('#');
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends