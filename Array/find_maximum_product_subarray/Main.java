//{ Driver Code Starts
import java.io.*;
import java.util.*;

  public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            String[] inputLine = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            System.out.println(new Solution().maxProduct(arr, n));
        }
    }
}

// } Driver Code Ends


class Solution {
    long getMax(int[] arr, int n) {
        long max_val = Integer.MIN_VALUE;
        for(int i = 0; i < n; i++)
            max_val = Math.max(max_val, arr[i]);
        return max_val;
    }
    // Function to find maximum product subarray
    long maxProduct(int[] arr, int n) {
        // code here
        long currMin = 1, currMax = 1, res = getMax(arr, n);
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) {
                currMin = 1;
                currMax = 1;
                continue;
            }
            long temp = currMax * arr[i];
            currMax = Math.max(arr[i], Math.max(currMax * arr[i], currMin * arr[i]));
            currMin = Math.min(arr[i], Math.min(temp, currMin * arr[i]));
            res = Math.max(res, currMax);
        }
        return res;
    }
}