//{ Driver Code Starts
    import java.util.*;
    import java.lang.*;
    import java.io.*;
    
    class GFG {
        public static void main (String[] args) {
    
            Scanner sc=new Scanner(System.in);
            int test=sc.nextInt();
            while(test-- > 0){
                int p=sc.nextInt();             // Take size of both the strings as input
                int q=sc.nextInt();
                
                String s1=sc.next();            // Take both the string as input
                String s2=sc.next();
                
                Solution obj = new Solution();
                
                System.out.println(obj.lcs(p, q, s1, s2));
            }
        }
    }
    // } Driver Code Ends
    
    
    class Solution
    {
        //Function to find the length of longest common subsequence in two strings.
        static int lcs(int x, int y, String s1, String s2)
        {
            // your code here
            int[] dp = new int[y + 1];
            for(int i = 0; i < x; i++) {
                int prev = dp[0];
                for(int j = 1; j < dp.length; j++) {
                    int temp = dp[j];
                    if(s1.charAt(i) != s2.charAt(j - 1)) dp[j] = Math.max(dp[j], dp[j - 1]);
                    else dp[j] = prev + 1;
                    prev = temp;
                }
            }
            return dp[dp.length - 1];
        }
    }