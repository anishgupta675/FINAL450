// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> nums){
        // code here
        int index1, index2, i;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                index1=i;
                break;
            }
        }

        //if there is no break point means it is decreasing sequence
        if(i<0){
            reverse(nums.begin(),nums.end());
            return nums;
        }

        //finding the value that is greater than the breakpoint
        for(int j=n-1;j>=0;j--)
        {
            if(nums[j]>nums[index1])
            {
                index2=j;
                break;
            }
        }

        // swaping both values then reversing them
        swap(nums[index1],nums[index2]);
        reverse(nums.begin()+index1+1,nums.end());
        return nums;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
