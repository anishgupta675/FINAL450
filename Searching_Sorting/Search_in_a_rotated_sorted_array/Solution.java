import java.util.*;
class Solution {
    private int binarySearch(int[] nums, int low, int high, int target) {
        if(low > high) return -1;
        if(low == high) return (nums[low] == target) ? low : -1;
        if(nums[low] == target) return low;
        if(nums[high] == target) return high;
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) return binarySearch(nums, low + 1, mid - 1, target);
        return binarySearch(nums, mid + 1, high - 1, target);
    }
    public int search(int[] nums, int target) {
        if(nums.length == 1) return (nums[0] == target) ? 0 : -1;
        int i = 0;
        for(i = 1; i < nums.length; i++)
            if(nums[i - 1] > nums[i]) break;
        if(i == nums.length) return binarySearch(nums, 0, nums.length - 1, target);
        int first_half = binarySearch(nums, 0, i - 1, target), second_half = binarySearch(nums, i, nums.length - 1, target);
        if(first_half >= 0) return first_half;
        return second_half;
    }
    public static void main(String[] args) throws Exception {}
}