// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void sort012(int a[], int n)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) count0++;
        else if(a[i] == 1) count1++;
        else if(a[i] == 2) count2++;
    }
    for(int i = 0; i < count0; i++)
        a[i] = 0;
    for(int i = count0; i < count0 + count1; i++)
        a[i] = 1;
    for(int i = count0 + count1; i < count0 + count1 + count2; i++)
        a[i] = 2;
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends
