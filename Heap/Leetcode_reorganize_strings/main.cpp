#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        if(n == 0)
            return "";
        vector<int> cnt(26, 0);
        for(auto a : s)
            cnt[a - 'a']++;
        int max = 0;
        char ch_max;
        for(int i = 0; i<26; i++)
            if(max < cnt[i]){
                max = cnt[i];
                ch_max = 'a' + i;
            }
        if(max > (n+1)/2)
            return "";
        int ind = 0;
        string res(n,' ');
        while(max){
            res[ind] = ch_max;
            ind+=2;
            max--;
        }
        cnt[ch_max - 'a'] = 0;
        for(int i=0; i<26; i++){
            while(cnt[i]){
                ind = ind>=n?1:ind;
                res[ind] = i+'a';
                ind+=2;
                cnt[i]--;
            }
        }
        return res;
    }
};

string s;
Solution sol;

int main() {
    getline(cin, s);
    cout << sol.reorganizeString(s) << endl;
    return 0;
}