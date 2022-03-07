// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends


//User function Template for C++

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void reverse(int *arr, int low, int high) {
    for(int i = low, j = high; i <= j; i++, j--)
        swap(&arr[i], &arr[j]);
}

void rotate(int arr[], int n)
{
    if(n == 0 || n == 1) return;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, 0);
    reverse(arr, 1, n - 1);
}
