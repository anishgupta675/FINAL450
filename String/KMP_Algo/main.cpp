// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:
	int lps(string s) {
	    // Your code goes here
	    int border = 0;
	    int *p = (int *)malloc(s.length() * sizeof(int));
	    p[0] = 0;
	    for(int i = 1; i < s.length(); i++) {
	        while(border > 0 && s[i] != s[border]) border = p[border - 1];
	        if(s[i] == s[border]) border++;
	        else border = 0;
	        p[i] = border;
	    }
	    return p[s.length() - 1];
	}
};

// { Driver Code Starts.

int main()
{


   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
