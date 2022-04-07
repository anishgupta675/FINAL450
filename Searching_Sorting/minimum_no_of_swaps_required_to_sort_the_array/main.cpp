// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>> vec;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        vector<bool>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int clen=0;
            if(vis[i]==1||vec[i].second==i)
            continue;

            int j=i;
            while(vis[j]==false)
            {
                vis[j]=true;
                clen++;
                j=vec[j].second;
            }
            ans+=clen-1;
        }

        return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
