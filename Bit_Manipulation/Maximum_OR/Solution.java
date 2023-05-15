import java.util.*;

class Solution {
    
    private static final Scanner sc = new Scanner(System.in);
    private static final Solution sol = new Solution();

    private int maximizeHamDist(int n1, int n2) {
        String binStr1 = Integer.toBinaryString(n1);
        String binStr2 = Integer.toBinaryString(n2);
        int lenDiff = Math.abs(binStr1.length() - binStr2.length());
        if(binStr1.length() < binStr2.length()) binStr1 = "0".repeat(lenDiff) + binStr1;
        else binStr2 = "0".repeat(lenDiff) + binStr2;
        int count = 0;
        for(int i = 0; i < binStr1.length(); i++) if(binStr1.charAt(i) != binStr2.charAt(i)) count++;
        return count;
    }

    public long maximumOr(int[] nums, int k) {
        if(nums.length == 1) return nums[0];
        int max_or = 0;
        for(int i = 0; i < k % nums.length; i++) max_or|= maximizeHamDist(nums[i] | nums[i + 1] << 1, nums[i] << 1 | nums[i + 1]);
        return max_or;
    }

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i = 0; i < n; i++) nums[i] = sc.nextInt();
        int k = sc.nextInt();
        System.out.println(sol.maximumOr(nums, k));
    }
}