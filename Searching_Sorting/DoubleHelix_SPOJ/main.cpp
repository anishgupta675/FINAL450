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

int32_t main() {
    dfile();
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        else {
            int a[n];
            for(int i = 0; i < n; i++)
                cin >> a[i];
            int m;
            cin >> m;
            int b[m];
            for(int i = 0; i < m; i++)
                cin >> b[i];

            int s1 = 0, s2 = 0, i = 0, j = 0, ma = 0;
            while(i < n && j < m) {
                if(a[i] < b[j]) s1+= a[i++];
                else if(b[j] < a[i]) s2+= b[j++];
                else {
                    ma = ma + max(s1, s2) + a[i];
                    s1 = s2 = 0;
                    i++;
                    j++;
                }
            }
            while(i < n)
                s1+= a[i++];
            while(j < m)
                s2+= b[j++];
            ma = ma + max(s1, s2);
            cout << ma << endl;
        }
    }

    return 0;
}
