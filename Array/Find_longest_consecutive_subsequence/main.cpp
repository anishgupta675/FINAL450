// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    int max(int a, int b) {
        return (a >= b) ? a : b;
    }
    // arr[] : the input array
    // N : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        vector<long>v(1000005,-1);
        for(int i=0;i<N;i++) v[arr[i]] = arr[i];

        int  maxl=INT_MIN,curl = 0;
        for(int i =0;i<1000005;i++)
        {
             if(v[i] != -1) curl++;
            else{
                 curl = 0;
            }
            if(maxl < curl)
            {
                maxl = curl;

             }
         }
        return maxl;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }

    return 0;
}  // } Driver Code Ends
