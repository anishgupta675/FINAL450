// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int min(int a, int b) {
    return (a <= b) ? a : b;
}

int minFlips (string S)
{
    // your code here
    int alt1 = 0, alt2 = 0;
    for(int i = 0; i < S.length(); i++) {
        if(i % 2) {
            if(S[i] == '0') alt1++;
            else alt2++;
        } else {
            if(S[i] == '0') alt2++;
            else alt1++;
        }
    }
    return min(alt1, alt2);
}
