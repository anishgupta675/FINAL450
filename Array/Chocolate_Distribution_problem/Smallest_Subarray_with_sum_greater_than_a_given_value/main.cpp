#include<bits/stdc++.h>

using namespace std;

int *arr = nullptr;

int getSub(int *arr, int n, int x) {
    int i = 0, j = 0, sum = 0, min_val = INT_MAX;
    while(i <= j && j < n) {
        while(sum <= x && j < n) sum+= arr[j++];
        while(sum > x && i < j) {
            min_val = min(min_val, j - i);
            sum-= arr[i];
            i++;
        }
    }
    return min_val;
}

int main() {
    int n, x;
    cin >> n;
    arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    cout << getSub(arr, n, x) << endl;
    free(arr);
    return 0;
}
