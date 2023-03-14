package Searching_Sorting.Aggressive_cows;

import java.util.Scanner;

class Solution {
    
    private static int res = 0;
    private static final Scanner sc = new Scanner(System.in);

    private static boolean checkStalls(int[] stall, int n, int c) {
        int cows = 1;
        int lastCowPosition = stall[0];
        for(int i : stall) {
            if(i - lastCowPosition >= n) {
                cows++;
                lastCowPosition = i;
                if(cows >= c) return true;
            }
        }
        return false;
    }

    private static void getStalls(int[] stall, int low, int high, int c) {
        if(low > high) return;
        int mid = (low + high) >> 1;
        if(checkStalls(stall, mid, c)) {
            res = mid;
            getStalls(stall, mid + 1, high, c);
        } else getStalls(stall, low, mid - 1, c);
    }

    private static void solve() {
        int n = sc.nextInt();
        int c = sc.nextInt();
        int[] stall = new int[n];
        for(int i = 0; i < n; i++) stall[i] = sc.nextInt();
        getStalls(stall, 1, stall[n - 1] - stall[0], c);
        System.out.println(res);
    }

    public static void main(String[] args) throws Exception {
        int tc = sc.nextInt();
        for(int t = 0; t < tc; t++) solve();
    }
}