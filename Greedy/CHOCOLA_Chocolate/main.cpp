#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int *cols = nullptr, *rows = nullptr;

int chocola() {
    int m, n, i, j, cost;
    cin >> m >> n;
    m--;
    n--;
    cols = (int *)malloc(m * sizeof(int));
    rows = (int *)malloc(n * sizeof(int));
    i = 0;
    j = 0;
    cost = 0;
    while(i < m && j < n) {
        if(cols[i] >= rows[j]) {
            cost+= cols[i] * (j + 1);
            i++;
        } else {
            cost+= rows[j] * (i + 1);
            j++;
        }
    }
    while(i < m) {
        cost+= cols[i] * (j + 1);
        i++;
    }
    while(j < n) {
        cost+= rows[j] * (i + 1);
        j++;
    }
    return cost;
}

void solve() {
    cout << chocola() << endl;
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