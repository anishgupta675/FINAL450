// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends


long long getMin(long long *a, int n) {
    long long min_val = a[0];
    for(int i = 0; i < n; i++)
        if(a[i] < min_val) min_val = a[i];
    return min_val;
}

long long getMax(long long *a, int n) {
    long long max_val = a[0];
    for(int i = 0; i < n; i++)
        if(a[i] > max_val) max_val = a[i];
    return max_val;
}

pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> res;
    res.first = getMin(a, n);
    res.second = getMax(a, n);
    return res;
}
