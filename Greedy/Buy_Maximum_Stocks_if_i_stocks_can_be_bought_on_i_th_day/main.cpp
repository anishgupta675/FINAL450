#include <bits/stdc++.h>
using namespace std;

int *price = nullptr;

// Return the maximum stocks
int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int> > v;
 
    // Making pair of product cost and number
    // of day..
    for (int i = 0; i < n; ++i)
        v.push_back(make_pair(price[i], i + 1));   
 
    // Sorting the vector pair.
    sort(v.begin(), v.end());   
 
    // Calculating the maximum number of stock
    // count.
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += min(v[i].second, k / v[i].first);
        k -= v[i].first * min(v[i].second,
                               (k / v[i].first));
    }
 
    return ans;
}

int main() {
    int n, k;
    cin >> n;
    price = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        cin >> price[i];
    cin >> k;
    cout << buyMaximumProducts(n, k, price) << endl;
    free(price);
    return 0;
}