// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int totalSum = 0 , currentSum = 0 , j = 0 ;
      
        for(int i = 0 ; i < n ; i++){
            totalSum += p[i].petrol - p[i].distance ;
            currentSum += p[i].petrol - p[i].distance ;
          
            if(currentSum < 0 ) {
                j = i + 1 ;
                currentSum = 0 ;
            }
        }
        return totalSum < 0 ? -1 : j ;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends