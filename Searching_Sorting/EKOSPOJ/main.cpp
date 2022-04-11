#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long *trees;

bool isWoodSufficient(int h) {
    long long wood = 0;
    for(int i = 0; i < n; i++)
        if(trees[i] >= h) wood+= (trees[i] - h);
    return wood >= m;
}

int main() {
    cin >> n >> m;
    trees = (long long *)malloc(n * sizeof(long long));
    for(int i = 0; i < n; i++)
        cin >> trees[i];
    // sort(trees);
    long long lo = trees[0], hi = trees[n - 1], mid;
    while(hi - lo > 1) {
        mid = (hi + lo) / 2;
        if(isWoodSufficient(mid)) lo = mid;
        else hi = mid - 1;
    }
    if(isWoodSufficient(hi)) cout << hi << endl;
    else cout << lo << endl;
}
