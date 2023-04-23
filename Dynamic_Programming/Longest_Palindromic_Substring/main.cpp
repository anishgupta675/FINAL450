#include<bits/stdc++.h>

using namespace std;

class Solution {
    int res_low = 0;
    int res_high = 0;
    int res_len = 0;
    void longestPalindrome(string s, int low, int high) {
        if(low < 0 || high >= s.length() || s[low] != s[high]) return;
        if(high - low + 1 > res_len) {
            res_low = low;
            res_high = high;
            res_len = high - low + 1;
        }
        longestPalindrome(s, low - 1, high + 1);
    }
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;
        for(int i = 0; i < s.length(); i++) {
            longestPalindrome(s, i, i);
            longestPalindrome(s, i, i + 1);
        }
        return s.substr(res_low, res_len);
    }
};

int main() {}