#include<bits/stdc++.h>
#define int long long int
using namespace std;

void dfile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int solve(int *a, int n, int par, int mid) {
    int time = 0;
    int paratha = 0;
    for(int i = 0; i < n; i++) {
        time = a[i];
        int j = 2;
        while(time < mid) {
            paratha++;
            time = time + (a[i] * j);
            j++;
        }
        if(paratha >= par) return 1;
    }
    return 0;
}

int32_t main() {
    dfile();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int par;
        cin >> par;
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int lb = 0;
        int ub = 0;
        int ans = 0;
        while(lb <= ub) {
            int mid = (lb + ub) / 2;
            if(solve(a, n, par, mid)) {
                ans = mid;
                ub = mid - 1;
            } else lb = mid + 1;
        }
        cout << ans << endl;
    }

    return 0;
}
