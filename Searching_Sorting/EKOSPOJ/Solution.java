package Searching_Sorting.EKOSPOJ;

import java.util.Scanner;

class Solution {

    private static int res = 0;
    private static final Scanner sc = new Scanner(System.in);

    private static int maximizeHeight(int[] tree) {
        int max_val = 0;
        for(int i : tree) max_val = Math.max(max_val, i);
        return max_val;
    }

    private static boolean validateTree(int[] tree, int mid, int m) {
        return (tree[mid] == m);
    }

    private static void getTree(int[] tree, int low, int high, int m) {
        if(low > high) return;
        int mid = (low + high) >> 1;
        if(validateTree(tree, mid, m)) {
            res = mid;
            getTree(tree, mid + 1, high, m);
        } else getTree(tree, low, mid - 1, m);
    }

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt(), m = sc.nextInt(), sum = 0;
        int[] tree = new int[n];
        for(int i : tree) {
            i = sc.nextInt();
            sum+= i;
        }
        if(sum < n) System.out.println(-1);
        else {
            getTree(tree, 0, maximizeHeight(tree), m);
            System.out.println(res);
        }
    }
}