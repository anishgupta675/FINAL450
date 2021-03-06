// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        int a[D];
        memset(a,0,sizeof(a));
        
        a[0]=1; // MSB cannot be zero
        S--;
        int i=D-1;
        while(i>=1 && S){ 
            a[i]=min(9,S); // digit can be atmost 9
            S-=a[i]; 
            i--;
        }
                
        if(S>0)
            a[0]+=S;
        
        string s;
        for(int i=0; i<D; i++){
            if(a[i]>9)
                return "-1";
            s.push_back('0'+a[i]);
        }
        return s;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends