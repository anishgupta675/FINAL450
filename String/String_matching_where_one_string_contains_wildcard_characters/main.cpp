#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        bool **table = (bool **)malloc((pLen + 1) * sizeof(bool *));
        for(int i = 0; i <= pLen; i++) {
            table[i] = (bool *)malloc((sLen + 1) * sizeof(bool));
            for(int j = 0; j <= sLen; j++) {
                if(0 == i && 0 == j) table[i][j] = true;
                else if(0 == i) table[i][j] = false;
                else if(0 == j) {
                    if('*' == p[i - 1]) table[i][j] = table[i - 1][j];
                    else table[i][j] = false;
                } else {
                    char pChar = p[i - 1];
                    char sChar = s[j - 1];
                    if('*' == pChar) {
                        table[i][j] = table[i - 1][j] || table[i][j - 1];
                        continue;
                    }
                    if('?' == pChar || pChar == sChar) {
                        table[i][j] = table[i - 1][j - 1];
                        continue;
                    }
                    table[i][j] = false;
                }
            }
        }
        return table[pLen][sLen];
    }
};

string s, p;
Solution sol;

int main() {
    getline(cin, s);
    getline(cin, p);
    if(sol.isMatch(s, p)) cout << "true";
    else cout << "false";
    return 0;
}
