package Searching_Sorting.Bishu_and_Soldiers;

/* IMPORTANT: Multiple classes and nested static classes are supported */

/*
 * uncomment this if you want to read input.
//imports for BufferedReader
*/
/*

//import for Scanner and other utility classes
*/
import java.util.*;
/*
*/

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

class TestClass {

    private static final Scanner sc = new Scanner(System.in);

    /*
    private static int getSum(int[] arr, int low, int high) {
        int sum = 0;
        for(int i = low; i < high; i++)
            sum+= arr[i];
        return sum;
    }
    */

    private static int[] getPrefixSum(int[] arr, int n) {
        int[] prefix_sum = new int[n];
        prefix_sum[0] = arr[0];
        for(int i = 1; i < n; i++)
            prefix_sum[i] = prefix_sum[i - 1] + arr[i];
        return prefix_sum;
    }

    // Template function to find greatest number smaller than or equal to a given target value 'q'
    private static int getIndex(int[] soldiers, int low, int high, int q) {
        int index = 0;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(soldiers[mid] <= q) {
                index = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return index + 1;
    }

    private static void solve() {
        int n = sc.nextInt();
        int[] soldiers = new int[n];
        for(int i = 0; i < n; i++)
            soldiers[i] = sc.nextInt();
        Arrays.sort(soldiers);
        int[] prefix_sum = getPrefixSum(soldiers, n);
        int q = sc.nextInt();
        // int[] rounds = new int[q];
        for(int i = 0; i < q; i++) {
            // rounds[i] = sc.nextInt();
            int index = getIndex(soldiers, 0, n - 1, sc.nextInt());
            System.out.println(index + " " + prefix_sum[index - 1]);
        }
    }

    public static void main(String args[] ) throws Exception {
        /* Sample code to perform I/O:
         * Use either of these methods for input

        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name = br.readLine();                // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        //Scanner
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();                 // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        */

        // Write your code here
        int tc = 1;
        // tc = sc.nextInt();
        for(int i = 0; i < tc; i++) {
            // System.out.print("Case #" + t + ": ");
            solve();
        }
    }
}
