#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void check(string &s,string compare)
    {
        int count=0;
        int m=s.length();
        int n=compare.length();
        int i=0;
        int j=0;
        while(i<m && j<n)
        {
            if(s[i]!=compare[j])
            {
                break;
            }
            i++;
            j++;
        }
        s.erase(i);//deleting elements after i'th index

    }
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        s+=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            check(s,strs[i]);
        }
        return s;
    }
};

vector<string> strs;
Solution sol;

int main() {
    int n;
    string data;
    cin >> n;
    for(int i = 0; i < n; i++) {
        getline(cin, data);
        strs.push_back(data);
    }
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}
