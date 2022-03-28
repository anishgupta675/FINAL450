// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void fillMap(unordered_map<char, int> &roman) {
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
    }

    int romanToDecimal(string &s) {
        // code here
        int res = 0, n = s.length();
        unordered_map<char, int> roman(7);
        fillMap(roman);
        for(int i = 0; i < n; i++) {
            if(i + 1 < n && roman[s[i + 1]] > roman[s[i]]) res-= roman[s[i]];
            else res+= roman[s[i]];
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends
