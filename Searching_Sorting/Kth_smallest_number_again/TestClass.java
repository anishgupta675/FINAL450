import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
class TestClass {

    private static Scanner sc = new Scanner(System.in);

    private static int[][] merge(int[][] intervals) {
        if(intervals.length <= 1) return intervals;
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });
        int[] current_interval = intervals[0];
        List<int[]> res = new ArrayList<int[]>();
        for(int i = 0; i < intervals.length; i++) {
            if(current_interval[1] >= intervals[i][0]) current_interval[1] = Math.max(current_interval[1], intervals[i][1]);
            else {
                res.add(current_interval);
                current_interval = intervals[i];
            }
        }
        res.add(current_interval);
        return res.toArray(new int[(res.size())][]);
    }

    private static int getKthSmallest(int[] range, int q) {
        if(q > range[1] - range[0] + 1) return -1;
        return range[0] + q - 1;
    }

    private static void solve() {
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[][] range = new int[n][2];
        for(int i = 0; i < n; i++) {
            range[i][0] = sc.nextInt();
            range[i][1] = sc.nextInt();
        }
        Arrays.sort(range, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });
        range = merge(range);
        for(int i = 0; i < q; i++) {
            for(int j = 0; j < range.length; j++)
                System.out.println(getKthSmallest(range[j], sc.nextInt()));
        }
    }

    public static void main(String args[] ) throws Exception {
        //BufferedReader
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // String name = br.readLine();                // Reading input from STDIN
        // System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        // Write your code here
        int tc = 1;
        tc = sc.nextInt();
        for(int i = 0; i < tc; i++) {
            // System.out.print("Case #" + t + ": ");
            solve();
        }
    }
}
