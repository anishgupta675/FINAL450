// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
   
    int i=0, j=n-1;
    long long int s=0;
   
    while(i+1<j)
    {
        s+= 2*arr[j--]-(arr[i]+arr[i+1]);
       
        i++;
    }
   
    s+= arr[j]-arr[0];
   
    if(n%2==0) s+=arr[j]-arr[j-1];
    return s;
}