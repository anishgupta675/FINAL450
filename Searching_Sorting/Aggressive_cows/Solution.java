package Searching_Sorting.Aggressive_cows;

import java.util.Scanner;

class Solution {
    
    private static int res = 0;
    private static final Scanner sc = new Scanner(System.in);

    private static void getStalls(int[] stall, int n, int c) {}

    private static void solve() {
        int n = sc.nextInt();
        int c = sc.nextInt();
        int[] stall = new int[n];
        for(int i = 0; i < n; i++) stall[i] = sc.nextInt();
        getStalls(stall, n, c);
        System.out.println(res);
    }

    public static void main(String[] args) throws Exception {
        int tc = sc.nextInt();
        for(int t = 0; t < tc; t++) solve();
    }
}