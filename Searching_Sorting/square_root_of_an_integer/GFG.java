//{ Driver Code Starts
//Initial Template for Java

import java.io.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.countSquares(N));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    int countSquares(int N) {
        // code here
        return (int)Math.sqrt(N - 1);
    }
}