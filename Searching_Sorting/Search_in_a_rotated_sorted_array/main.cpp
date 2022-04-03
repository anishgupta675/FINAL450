#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchUtil(vector<int> &arr, int l, int h, int key) {
        if(l > h) return -1;

        int mid = (l + h) / 2;
        if(arr[mid] == key) return mid;

        /* If arr[l...mid] is sorted */
        if(arr[l] <= arr[mid]) {
            /* As this subarray is sorted, we can quickly
            check if key lies in half or other half */
            if(key >= arr[l] && key <= arr[mid]) return searchUtil(arr, l, mid - 1, key);
            /*If key not lies in first half subarray,
            Divide other half  into two subarrays,
            such that we can quickly check if key lies
            in other half */
            return searchUtil(arr, mid + 1, h, key);
        }

        /* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
        must be sorted subarray */
        if(key >= arr[mid] && key <= arr[h]) return searchUtil(arr, mid + 1, h, key);

        return searchUtil(arr, l, mid - 1, key);
    }

    int search(vector<int>& nums, int target) {
        return searchUtil(nums, 0, nums.size() - 1, target);
    }
};

vector<int> nums;
Solution sol;

int main() {
    int n, data, target;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        nums.push_back(data);
    }
    cin >> target;
    cout << sol.search(nums, target) << endl;
    return 0;
}
