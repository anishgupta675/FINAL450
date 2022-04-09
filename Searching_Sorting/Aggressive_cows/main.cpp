#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll *arr;

ll getMaxDistance(ll *arr, int n, int c) {
    sort(arr, arr + n);
    int lb = arr[0], ub = arr[n - 1], ans = 0;
    while(lb <= ub) {
        int mid = (lb + ub) / 2, cow = 1, prev = arr[0];
        for(int i = 1; i < n; i++) {
            if(arr[i] - prev > mid) {
                cow++;
                prev = arr[i];
                if(c == cow) break;
            }
        }
        if(cow == c) {
            ans = mid;
            lb = mid + 1;
        } else ub = mid - 1;
    }
    return ans;
}

void solve() {
    int n, c;
    cin >> n >> c;
    arr = (ll *)malloc(n * sizeof(ll));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << getMaxDistance(arr, n, c) << endl;
    free(arr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
