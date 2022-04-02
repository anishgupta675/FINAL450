// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    bool found = false;
    int first_index = -1, last_index = -1;
    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            last_index = i;
            if(!found) {
                first_index = i;
                found = true;
            }
        }
    }
    res.push_back(first_index);
    res.push_back(last_index);
    return res;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends
