#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nums;

int count(vector <int>& nums, int& mid)
{//function to calculate number of elements less than equal to mid
        int cnt = 0;
         
        for(int i = 0; i < nums.size(); i++)
           if(nums[i] <= mid)
              cnt++;
         
        return cnt;
}
     
 
int kthSmallest(vector <int> nums, int& k)
{
        int low = INT_MAX;
        int high = INT_MIN;
        //calculate minimum and maximum the array.
        for(int i = 0; i < nums.size(); i++)
        {
            low = min(low, nums[i]);
            high = max(high, nums[i]);
        }
        //Our answer range lies between minimum and maximum element of the array on which Binary Search is Applied
        while(low < high)
        {
            int mid = low + (high - low) / 2;
           /*if the count of number of elements in the array less than equal to mid is less than k
             then increase the number. Otherwise decrement the number and try to find a better answer.
           */
            if(count(nums, mid) < k)
               low = mid + 1;
                
            else
                high = mid;
        }
         
        return low;
}

int main() {
    int n, data, k;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        nums.push_back(data);
    }
    cin >> k;
    cout << kthSmallest(nums, k) << endl;
    return 0;
}