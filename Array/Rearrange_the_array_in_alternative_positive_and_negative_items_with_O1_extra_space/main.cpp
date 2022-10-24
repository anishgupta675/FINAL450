#include<bits/stdc++.h>

using namespace std;

int *arr = nullptr;

void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void rearrange(int arr[], int n)
{
    int i = 0, j = n - 1;
    while(i < j) {
        while(i < n && arr[i] > 0)
            i++;
        while(j > 0 && arr[j] < 0)
            j++;
        if(i < j) swap(arr, i, j);
    }
    if(i == 0 || i == n) return;
    int k = 0;
    while(k < n && i < n) {
        swap(arr, i, k);
        i+= 1;
        k+= 2;
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
