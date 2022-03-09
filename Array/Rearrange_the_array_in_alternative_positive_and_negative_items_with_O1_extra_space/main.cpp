#include<bits/stdc++.h>

using namespace std;

int *arr = nullptr;

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void rearrange(int arr[], int n)
{
    int i = 0, j = n-1;

    // shift all negative values to the end
    while (i < j) {
        while (i <= n - 1 and arr[i] > 0)
            i += 1;
        while (j >= 0 and arr[j] < 0)
            j -= 1;
        if (i < j )
            swap(&arr[i], &arr[j]);
    }

    // i has index of leftmost
    // negative element
    if (i == 0 || i == n)
        return;

    // start with first positive
    // element at index 0

    // Rearrange array in alternating
    // positive &
    // negative items
    int k = 0;
    while (k < n && i < n ) {
        // swap next positive
        // element at even position
        // from next negative element.
        swap(&arr[k], &arr[i]);
        i = i + 1;
        k = k + 2;
    }
}

void display(int *arr, int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    rearrange(arr, n);
    display(arr, n);
    free(arr);
    return 0;
}
