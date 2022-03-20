#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res {"1"};
        for (int i = 2; i <= n; ++i) {
            res = countAndSayHelper(res);
        }
        return res;
    }
private:
    string countAndSayHelper(const string& str) {
        string res;
        for (int i = 0; i < str.size(); ++i) {
            int count = 1;
            while (i < str.size() -1 && str[i] == str[i+1]) {
                count++;
                i++;
            }
            res += to_string(count) + str[i];
        }
        return res;
    }
};

Solution sol;

int main() {
    int n;
    cin >> n;
    cout << sol.countAndSay(n) << endl;
    return 0;
}
