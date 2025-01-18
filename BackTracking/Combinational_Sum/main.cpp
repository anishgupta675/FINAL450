// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void findcomb(int idx,int B,vector<int> &A,vector<vector<int>> &ans,vector<int> &ha){
        if(idx==A.size()){
            if(B==0){
                sort(ha.begin(),ha.end());
                ans.push_back(ha);
            }
            return;
        }
        if(A[idx]<=B){
            ha.push_back(A[idx]);
            findcomb(idx,B-A[idx],A,ans,ha);
            ha.pop_back();
        }
        findcomb(idx+1,B,A,ans,ha);
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        vector<vector<int>> ans;
        vector<int> ha;
        findcomb(0,B,A,ans,ha);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends