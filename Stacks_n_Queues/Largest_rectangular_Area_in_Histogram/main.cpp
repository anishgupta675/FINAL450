// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector< long long >left ;
        vector< long long >right ;
        stack<pair< long long , int >> s ;
     
       
        for( int i = 0 ; i<n ; i++)
        {
                while( !s.empty() && s.top().first >= arr[i])
                {
                    s.pop() ;
                }
           
            
               
                if(!s.empty())
                {
                    left.push_back(s.top().second) ;
                }
                else{
                        left.push_back(-1) ;
                }
           
           
           
            s.push( { arr[i] , i } ) ;
        }
       
        while( !s.empty() )
        {
            s.pop() ;
        }
               
               
               
               
            for( int i = n-1 ; i>=0 ; i--)
        {
                while( !s.empty() && s.top().first >= arr[i])
                {
                    s.pop() ;
                }
           
            
               
                if(!s.empty())
                {
                    right.push_back(s.top().second) ;
                }
                else{
                        right.push_back(n) ;
                }
           
            s.push( {arr[i] , i } ) ;
           
           
           
        }
       
        long long mx = 0 ;
        reverse( right.begin() , right.end()) ;
        for( int i = 0 ; i<n ; i++)
        {
            mx = max( mx , arr[i]*(right[i]-left[i]-1)) ;
        }
       
        return mx ;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends