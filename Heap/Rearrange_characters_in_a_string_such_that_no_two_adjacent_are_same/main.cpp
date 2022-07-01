#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--) {
	    string s;
	    cin>>s;
	    
	    int n = s.length();
	    unordered_map<int, int> m;
	    int max=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        m[s[i]]++;
	        
	        if(m[s[i]]>max)
	            max=m[s[i]];
	    }
	    
	    if(max<=n-max+1)
	        cout<<1<<endl;
	    else
	        cout<<0<<endl;
	}
	return 0;
}