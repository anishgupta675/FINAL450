#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index1, index2, i;
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
            return;
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
    }
};

vector<int> nums;
Solution sol;

void display(vector<int> nums) {
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

int main() {
    int n, data;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        nums.push_back(data);
    }
    sol.nextPermutation(nums);
    display(nums);
    return 0;
}
