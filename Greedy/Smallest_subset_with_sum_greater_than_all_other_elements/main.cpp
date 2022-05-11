#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int *arr = nullptr;

// function to find minimum elements needed.
int minElements(int arr[], int n)
{
    // calculating HALF of array sum
    int halfSum = 0;
    for (int i = 0; i < n; i++)
        halfSum = halfSum + arr[i];   
    halfSum = halfSum / 2;
 
    // sort the array in descending order.
    sort(arr, arr + n, greater<int>());
 
    int res = 0, curr_sum = 0;
    for (int i = 0; i < n; i++) {
 
        curr_sum += arr[i];
        res++;
 
        // current sum greater than sum
        if (curr_sum > halfSum)        
            return res;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minElements(arr, n) << endl;
    free(arr);
    return 0;
}