#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int min(int a, int b) {
        return (a <= b) ? a : b;
    }
    int max(int a, int b) {
        return (a >= b) ? a : b;
    }
    int maxProfit(vector<int>& prices) {
        int max_val = 0, min_val = prices[0];
        for(int i = 0; i < prices.size(); i++) {
            min_val = min(min_val, prices[i]);
            max_val = max(max_val, prices[i] - min_val);
        }
        return max_val;
    }
};

vector<int> prices;
Solution sol;

int main() {
    int n, data;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        prices.push_back(data);
    }
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
