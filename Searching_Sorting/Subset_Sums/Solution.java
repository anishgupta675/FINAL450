import java.util.*;

class Solution {

    private static final Scanner sc = new Scanner(System.in);

    private static List<Integer> generateSubsetSumArray(int[] s, int left, int right) {
        double size = Math.pow(2, right - left + 1);
        List<Integer> ssa = new ArrayList<Integer>();
        for(int i = 0; i < size; i++) {
            int j = left, curr_sum = 0;
            while(i != 0 && j <= right) {
                if((i & 1) != 0) curr_sum+= s[j];
                i>>= 1;
                j++;
            }
            ssa.add(curr_sum);
        }
        return ssa;
    }

    private static long countSubsets(int[] s, int n, int a, int b) {
        int mid = (n - 1) / 2;
        List<Integer> arr1 = generateSubsetSumArray(s, 0, mid);
        List<Integer> arr2 = generateSubsetSumArray(s, mid + 1, n - 1);
        Collections.sort(arr2);
        long ans = 0;
        for(int i = 0; i < arr1.size(); i++) ans+= Collections.binarySearch(arr2, b - arr1.get(i)) - Collections.binarySearch(arr2, (a - arr1.get(i)));
        return ans;
    }

    public static void main(String[] args) {
        int n = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt();
        int[] s = new int[n];
        for(int i = 0; i < n; i++) s[i] = sc.nextInt();
        System.out.println(countSubsets(s, n, a, b));
    }
}