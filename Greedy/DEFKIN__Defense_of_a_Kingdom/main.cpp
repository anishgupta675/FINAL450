#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

pair<int, int> *tower = NULL;

int getPenalty(pair<int, int> *tower, int n, int w, int h) {
	int max_width = tower[0].first, max_height = tower[0].second;
	for(int i = 1; i < n; i++) {
		if(i == n - 1) {
			max_width = max(max_width, w - tower[i].first);
			max_height = max(max_height, h - tower[i].second);
		} else {
			max_width = max(max_width, tower[i + 1].first - tower[i].first);
			max_height = max(max_height, tower[i + 1].second - tower[i].second);
		}
	}
	return max_width * max_height;
}

void solve() {
    int w, h, n;
    cin >> w >> h >> n;
    tower = (pair<int, int> *)malloc(n * sizeof(pair<int, int>));
    for(int i = 0; i < n; i++)
    	cin >> tower[i].first >> tower[i].second;
    cout << getPenalty(tower, n, w, h) << endl;
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