import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
class TestClass {

    private static Scanner sc = new Scanner(System.in);

    private static int maximizeSubsquare(int[][] a, int[][] b, int n, int m, int x, int y) {
        int min_size = Math.min(n, Math.min(m, Math.min(x, y))), low = 1, high = min_size, ans = 0;
        int[] pwr_arr = new int[(min_size * min_size) + 1];
        int[] roll_hash = new int[Math.max(m, y)];
        pwr_arr[0] = 1;
        for(int i = 0; i < pwr_arr.length; i++) pwr_arr[i] = (pwr_arr[i - 1] * 1000) % Integer.MAX_VALUE;
        while(low <= high) {
            int mid = low + ((high - low) >> 1), p_ptr = 0, i = mid - 1;
            roll_hash[0] = 0;
            while(i >= 0) {
                int j = mid - 1;
                while(j >= 0) {
                    // TODO
                    p_ptr++;
                    j--;
                }
            }
        }
        return ans;
    }

    private static void solve() {
        int n = sc.nextInt(), m = sc.nextInt();
        int[][] a = new int[n][m];
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) a[i][j] = sc.nextInt();
        int x = sc.nextInt(), y = sc.nextInt();
        int[][] b = new int[x][y];
        for(int i = 0; i < x; i++) for(int j = 0; j < y; j++) b[i][j] = sc.nextInt();
        System.out.println(maximizeSubsquare(a, b, n, m, x, y));
    }

    public static void main(String args[] ) throws Exception {
        //BufferedReader
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // String name = br.readLine();                // Reading input from STDIN
        // System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        int tc = 1;
        // tc = sc.nextInt();
        for(int i = 0; i < tc; i++) {
            // System.out.print("Case #" + t + ": ");
            solve();
        }
    }
}
