#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<pair<int, int>> buy, sell;

int getWork(vector<pair<int, int>> buy, vector<pair<int, int>> sell) {
    int i = 0, j = 0, work = 0;
    while(buy.empty() && sell.empty()) {
        if(i < buy.size() && j < sell.size()) {
            int wine = min(buy[i].first, sell[i].first);
            work+= wine * abs(buy[i].second - sell[i].second);
            buy[i].first-= wine;
            sell[i].first-=wine;
        }
        if(buy[i].first == 0) buy.erase(buy.begin() + i);
        if(sell[j].first == 0) sell.erase(sell.begin() + j);
        i++;
        j++;
    }
    return work;
}

void solve() {
    int n, data;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        if(data > 0) buy.push_back(make_pair(data, i));
        else if(data < 0) sell.push_back(make_pair(abs(data), i));
    }
    cout << getWork(buy, sell) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}