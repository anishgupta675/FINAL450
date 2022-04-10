#include<bits/stdc++.h>

using namespace std;

int *arr;

pair<int, int> partitionIndex(int, int, int *);

void __swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void quickSort(int left, int right, int *arr) {
    int size = right - left + 1;
    if(size < 2) return;
    if(size == 2) {
        if(arr[left] > arr[right]) __swap(&arr[left], &arr[right]);
        return;
    }
    pair<int, int> mid = partitionIndex(left, right, arr);
    int mid1 = mid.first;
    int mid2 = mid.second;
    if(mid1 >= left) quickSort(left, mid1, arr);
    if(mid2 <= right) quickSort(mid2, right, arr);
}

pair<int, int> partitionIndex(int left, int right, int *arr) {
    int idx = left + (rand() % (right - left));
    __swap(&arr[idx], &arr[right]);
    int pivot = arr[right], i = left, j = left, k = right;
    while(i <= k) {
        if(arr[i] < pivot) {
            __swap(&arr[i], &arr[j]);
            i++;
            j++;
        } else if(arr[i] == pivot) i++;
        else {
            __swap(&arr[i], &arr[k]);
            i--;
        }
    }
    return {j - 1, k + 1};
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
    quickSort(0, n - 1, arr);
    display(arr, n);
    free(arr);
    return 0;
}
