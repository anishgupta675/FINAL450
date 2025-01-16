#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int curr_ptr = 0, curr_ptr2 = 0, fast_ptr = 0;
        while(1) {
            curr_ptr = nums[curr_ptr];
            fast_ptr = nums[nums[fast_ptr]];
            if(curr_ptr == fast_ptr) break;
        }
        while(1) {
            curr_ptr = nums[curr_ptr];
            curr_ptr2 = nums[curr_ptr2];
            if(curr_ptr == curr_ptr2) return curr_ptr;
        }
        return 0;
    }
};

vector<int> nums;
Solution sol;

int main() {
    int n, data;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        nums.push_back(data);
    }
    cout << sol.findDuplicate(nums) << endl;
    return 0;
}
