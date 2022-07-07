#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int *pos_arr = nullptr, *speed_arr = nullptr;

void pickupchicks() {
    int c, n, k, b, t, count, swaps, impossibles, act_dist, possible_dist;
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> n >> k >> b >> t;
        pos_arr = (int *)malloc(n * sizeof(int));
        speed_arr = (int *)malloc(n * sizeof(int));
        count = 0;
        swaps = 0;
        impossibles = 0;
        for(int j = n - 1; j >= 0; j--) {
            act_dist = b - pos_arr[j];
            possible_dist = t * speed_arr[j];
            if(possible_dist >= act_dist) {
                count++;
                if(impossibles > 0) swaps+= impossibles;
            } else impossibles++;
            if(count >= k) {
                cout << i + 1 << " " << swaps << endl;
                break;
            }
        }
        if(count < k) cout << i + 1 << endl;
    }
}

void solve() {
    pickupchicks();
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