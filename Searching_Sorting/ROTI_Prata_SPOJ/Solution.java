import java.util.Arrays;
import java.util.Scanner;

public class Solution {

    private static int res = 0;
    private static final Scanner sc = new Scanner(System.in);

    private static boolean checkTime(int[] rank, int mid, int p) {
        int time = 0;
        for(int i : rank) {
            if(p == 0) break;
            time+= (((1 - (i * 2)) + (int)Math.sqrt((int)Math.pow((i * 2) - 1, 2) + (i * 100))) / (i * 2));
            p--;
        }
        return (time <= mid);
    }

    private static void getTime(int[] rank, int low, int high, int p) {
        if(low > high) return;
        int mid = (low + high) >> 1;
        if(checkTime(rank, mid, p)) {
            res = mid;
            getTime(rank, low, mid - 1, p);
        } else getTime(rank, mid + 1, high, p);
    }

    private static void solve() {
        int p = sc.nextInt(), l = sc.nextInt();
        int[] rank = new int[l];
        for(int i : rank) i = sc.nextInt();
        Arrays.sort(rank);
        getTime(rank, 1, p * 8, p);
        System.out.println(res);
    }

    public static void main(String[] args) throws Exception {
        int tc = 1;
        tc = sc.nextInt();
        for(int t = 0; t < tc; t++) {
            solve();
        }
    }
}