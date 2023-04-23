//{ Driver Code Starts
    import java.util.*;
    class GFG
    {
        public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            sc.nextLine();
            while(t>0)
            {
                String str = sc.nextLine();
                //System.out.println(str.length());
                Solution ob  = new Solution();
                System.out.println(ob.countPS(str));
            t--;
            }
        }
    }
    // } Driver Code Ends
    
    
    /*You are required to complete below method */
    
    class Solution
    {
        
        int MOD = 1000000007;
        long[][] dp;
        
        private long countPS(String str, int i, int j) {
            if(i > j) return 0;
            if(dp[i][j] != 0) return dp[i][j];
            if(i == j) return dp[i][j] = 1;
            if(str.charAt(i) == str.charAt(j)) return (1 + (countPS(str, i + 1, j) % MOD) + (countPS(str, i, j - 1) % MOD)) % MOD;
            return (MOD + (countPS(str, i + 1, j) % MOD) + (countPS(str, i, j - 1) % MOD) - (countPS(str, i + 1, j - 1) % MOD)) % MOD;
        }
        
        long countPS(String str)
        {
            // Your code here
            dp = new long[str.length()][str.length()];
            return countPS(str, 0, str.length() - 1);
        }
    }