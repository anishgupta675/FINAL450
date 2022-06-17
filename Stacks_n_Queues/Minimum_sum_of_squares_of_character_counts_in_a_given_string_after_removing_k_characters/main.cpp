// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int sum = 0;
        priority_queue<int> pq;
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++)
            m[s[i]]++;
        for(auto x:m)
            pq.push(x.second);
        while(k) {
            int x = pq.top();
            pq.pop();
            x--;
            pq.push(x);
            k--;
        }
        while(!pq.empty()) {
            int d = pq.top();
            sum+= pow(d, 2);
            pq.pop();
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends