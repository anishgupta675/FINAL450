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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](auto &left, auto &right) {
            return left[0] < right[0];
        });
        int k = 0;
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= res[k][1]) {
                res[k][0] = min(res[k][0], intervals[i][0]);
                res[k][1] = max(res[k][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
                k++;
            }
        }
        return res;
    }
};

vector<vector<int>> intervals;
Solution sol;

int main() {
    int n, datum;
    vector<int> data;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> datum;
            data.push_back(datum);
        }
        intervals.push_back(data);
    }
    intervals = sol.merge(intervals);
    for(int i = 0; i < intervals.size(); i++) {
        for(int j = 0; j < intervals[i].size(); j++)
            cout << intervals[i][j] << " ";
        cout << endl;
    }
    return 0;
}