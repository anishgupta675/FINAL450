#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int *a = nullptr;

void solve() {
    int n, ones = 0;
    cin >> n;
    a = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) ones++;
    }
    sort(a, a + n, greater<int>());
    for(int i = 0; i < ones; i++)
        cout << "1 ";
    
    if((n - ones) == 2 && a[0] == 3 && a[1] == 2) cout << "2 3" << endl;
    else {
        for(int i = 0; i < (n - ones); i++)
            cout << a[i] << " ";
        cout << endl;
    }
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