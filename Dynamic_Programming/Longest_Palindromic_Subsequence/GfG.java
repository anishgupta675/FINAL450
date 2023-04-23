//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    String s = sc.next();
                    Solution obj = new Solution();
                    System.out.println(obj.longestPalinSubseq(s));
                }
                
        }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    
    private int[][] dp;
    
    public int longestPalinSubseq(String S)
    {
        //code here
        if(S.length() == 1) return 1;
        if(S.length() == 2) return (S.charAt(0) == S.charAt(1) ? 2 : 1);
        dp = new int[S.length()][S.length()];
        for(int i = 1; i <= S.length(); i++) {
            for(int j = 0; j <= S.length() - i; j++) {
                int k = i + j - 1;
                if(i == 1) {
                    dp[j][k] = 1;
                    continue;
                }
                if(S.charAt(j) == S.charAt(k)) dp[j][k] = dp[j + 1][k - 1] + 2;
                else dp[j][k] = Math.max(dp[j + 1][k], dp[j][k - 1]);
            }
        }
        return dp[0][S.length() - 1];
    }
}