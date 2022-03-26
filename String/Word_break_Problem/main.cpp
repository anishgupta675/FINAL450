// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string &s,int n,int i,unordered_set<string> &words, vector<int> &dp)
    {
        if(i==n)
            return 1;

        int j=i;
        if(dp[j]==-1)
        {
            string t="";
            for(i;i<n;i++)
            {
                t+=s[i];
                if(words.find(t)!=words.end())
                {
                    if(wordBreak(s,n,i+1,words,dp))
                    {
                        dp[j]=1;
                        return 1;
                    }
                }
            }
            dp[j]=0;
        }

       return dp[j]==1;
    }

    int wordBreak(string s, vector<string> &wordDict) {
        //code here
        unordered_set<string> words(wordDict.begin(),wordDict.end());

        int n=s.length();
        vector<int> dp(n+1,-1);

        return wordBreak(s,n,0,words,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends
