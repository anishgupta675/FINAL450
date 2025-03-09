#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int find_removal(string s){
        stack<char>st;
        for(int i=0;i<s.size();i++){
                if(s[i]==')'){
                    if(st.size() and st.top()=='(')
                        st.pop();
                    else
                    st.push(s[i]);
            }else if(s[i]=='('){
                st.push(s[i]);
            }
        }
        return st.size();
    }
    
    void solve(string s,vector<string>&ans,unordered_map<string,bool>&mp,int min_removals){
        if(mp[s])return ;
        mp[s]=1;
        if(min_removals==0){
            int removals_needed=find_removal(s);
            if(removals_needed==0)
                ans.push_back(s);
            return;
        }
        
        for(int i=0;i<s.size();i++){
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            string join=left+right;
            solve(join,ans,mp,min_removals-1);
        }
    }
    
    
    vector<string> removeInvalidParentheses(string s) {
        unordered_map<string,bool>mp;
        int min_removals=find_removal(s);
        vector<string>ans;
        solve(s,ans,mp,min_removals);
        return ans;
    }
};

string s;
Solution sol;

void display(vector<string> res) {
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << "\n";
}

int main() {
    getline(cin, s);
    vector<string> res = sol.removeInvalidParentheses(s);
    display(res);
    return 0;
}