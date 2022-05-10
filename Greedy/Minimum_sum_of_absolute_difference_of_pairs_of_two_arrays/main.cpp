#include <bits/stdc++.h>
using namespace std;

long long int *a = nullptr, *b = nullptr;

// Returns minimum possible pairwise absolute
// difference of two arrays.
long long int findMinSum(long long int a[],long long int b[], int n)
{
    // Sort both arrays
    sort(a, a+n);
    sort(b, b+n);
 
    // Find sum of absolute differences
    long long int sum= 0 ;
    for (int i=0; i<n; i++)
        sum = sum + abs(a[i]-b[i]);
 
    return sum;
}

int main() {
    int n;
    cin >> n;
    a = (long long int *)malloc(n * sizeof(long long int));
    for(int i = 0; i < n; i++)
        cin >> a[i];
    b = (long long int *)malloc(n * sizeof(long long int));
    for(int i = 0; i < n; i++)
        cin >> b[i];
    cout << findMinSum(a, b, n) << endl;
    free(b); free(a);
    return 0;
}