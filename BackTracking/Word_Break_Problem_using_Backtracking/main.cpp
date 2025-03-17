// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    map<string, int> mp;
    void solve(vector<string> &res, vector<string> temp, string s,int i, int j){
        if(i==s.size()){
            string p=temp[0];
            for(int i=1; i<temp.size(); i++)
                p=p+ ' ' +temp[i];
            res.push_back(p);
            return;
        }
        string t="";
        for(int k=i; k<=j; k++){
            t.push_back(s[k]);
            if(mp.find(t)!=mp.end()){
                temp.push_back(t);
                solve(res,temp,s,k+1,j);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        int l=s.size();
        vector<string> res;
        vector<string> temp;
        for(int i=0; i<n; i++)
            mp[dict[i]]++;
        solve(res,temp,s,0,l-1);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends