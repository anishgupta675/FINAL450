//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> res;
		    for(int mask = 0; mask < (1 << s.length()); mask++) {
		        string data = "";
		        for(int i = 0; i < s.length(); i++) if(mask & (1 << i)) data+= s[i];
		        s.erase(remove(s.begin(), s.end(), ' '), s.end());
		        if(data.compare("")) res.push_back(data);
		    }
		    sort(res.begin(), res.end());
		    return res;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends