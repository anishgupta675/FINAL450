// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> v;
            string s, original;
            s=S;
            original=s;

            int j=1,n=s.size(),k=0, check=0;
            unordered_map<string,int> m;

            if(n==1) {

                v.push_back(s);
                return v;
            }
            if(n==2) {
                v.push_back(s);
                swap(s[0],s[1]);
                v.push_back(s);
                return v;

            }
            for(int i=0; i<n; i++) {
                swap (s[0],s[k]);
                string temp=s;
                do {
                    check++;
                    swap(s[j],s[j+1]);
                    m[s]++;
                    //   cout<<s<<" ";
                    j++;
                    if(j==n-1) j=1;

                } while (s!=temp);
                k++;
                s=original;
            }
            // cout<<"\n";
            for (auto x : m)
                v.push_back( x.first );
            // cout<<"\n"<<check;
            sort(v.begin(),v.end());
            return v;
        }
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
