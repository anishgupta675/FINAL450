import java.util.Scanner;

public class Solution {

    private static int res = 0;
    private static final Scanner sc = new Scanner(System.in);

    private static boolean checkSum(int[] v, int mid, int n) {
        return (v[mid] == n);
    }

    private static void getSum(int[] v, int low, int high, int n) {
        if(low > high) return;
        int mid = (low + high) >> 1;
        if(checkSum(v, mid, n)) {
            res = mid;
            getSum(v, mid + 1, high, n);
        } else getSum(v, low, mid - 1, n);
    }

    private static void solve() {
        int n = sc.nextInt();
        int[] v = new int[n];
        for(int i : v) i = sc.nextInt();
        getSum(v, 0, n - 1, n);
    }

    public static void main(String[] args) throws Exception {
        int tc = 1;
        tc = sc.nextInt();
        for(int t = 0; t < tc; t++) {
            solve();
        }
    }
}