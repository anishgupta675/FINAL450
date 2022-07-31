#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool helper(vector<int> nums,int sum)
    {
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        bool left=false,right=false;
     for(int i=0;i<n;i++)
         dp[i][0]=true;
        if(sum>=nums[0])
         dp[0][nums[0]]=true;
     
     for(int i=1;i<n;i++)
     {
     for(int target=1;target<=sum;target++){    
       if(target>=nums[i])
        left=dp[i-1][target-nums[i]];
        right=dp[i-1][target];
      dp[i][target]=(left|right);
     }
    }
       return dp[n-1][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
      
        if(sum%2!=0)
            return false;
       return helper(nums,sum/2);
    }
};

Solution sol;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    cout << sol.canPartition(nums) << endl;
    nums.clear();
    return 0;
}