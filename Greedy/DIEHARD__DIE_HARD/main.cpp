#include <iostream>
#include <vector>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int **dp = nullptr;

int getTime(int h, int a, int i) {
    if(h <= 0 || a <= 0) return 0;
    if(dp[h][a] != -1) return dp[h][a];
    int x = 0, y = 0, z = 0;
    if(i != 1) x = 1 + getTime(h + 3, a + 2, 1);
    if(i != 2) y = 1 + getTime(h - 5, a - 10, 2);
    if(i != 3) z = 1 + getTime(h - 20, a + 5, 3);
    return dp[h][a] = max(max(x, y), z);
}

void solve() {
    int health, armor;
    cin >> health >> armor;
    dp = (int **)malloc((health + 1) * sizeof(int *));
    for(int i = 0; i < health + 1; i++) {
        dp[i] = (int *)malloc((armor + 1) * sizeof(int));
        for(int j = 0; j < armor + 1; j++)
            dp[i][j] = -1;
    }
    cout << max(max(getTime(health + 3, armor + 2, 1), getTime(health - 5, armor - 10, 2)), getTime(health - 20, armor + 5, 3)) << endl;
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