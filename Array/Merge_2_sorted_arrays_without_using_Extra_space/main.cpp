// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int *arr = (int *)malloc((n + m) * sizeof(int));
	    for(int i = 0; i < n; i++)
	        arr[i] = arr1[i];
	    for(int j = 0; j < m; j++)
	        arr[n + j] = arr2[j];
	    sort(arr, arr + n + m);
	    for(int i = 0; i < n; i++)
	        arr1[i] = arr[i];
	    for(int j = 0; j < m; j++)
	        arr2[j] = arr[n + j];
	    free(arr);
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
