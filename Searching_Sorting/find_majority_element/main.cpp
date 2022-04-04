// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {

        // your code here
        int max_val = 0, max_freq = 0;
        unordered_map<int, int> freq(size);
        for(int i = 0; i < size; i++)
            freq[a[i]]++;
        for(auto i : freq) {
            if(i.second >= max_freq) {
                max_freq = i.second;
                max_val = i.first;
            }
        }
        if(max_freq > size / 2) return max_val;
        return -1;
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];

        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
