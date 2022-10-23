//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int k = Integer.parseInt(inputLine[1]);
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            int ans = new Solution().getPairsCount(arr, n, k);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    int lower_bound(int[] arr, int low, int high, int x) {
        if(low > high) return low;
        int mid = low + ((high - low) / 2);
        if(arr[mid] <= x) return lower_bound(arr, low, mid - 1, x);
        return lower_bound(arr, mid + 1, high, x);
    }
    int upper_bound(int[] arr, int low, int high, int x) {
        if(low > high || low == arr.length) return low;
        int mid = low + ((high - low) / 2);
        if(arr[mid] <= x) return upper_bound(arr, mid + 1, high, x);
        return upper_bound(arr, low, mid - 1, x);
    }
    int getPairsCount(int[] arr, int n, int k) {
        // code here
        int count = 0;
        for(int i = 0; i < n - 1; i++)
            count+= upper_bound(arr, i + 1, n - 1, k - arr[i]) - lower_bound(arr, i + 1, n - 1, k - arr[i]);
        return count;
    }
}
