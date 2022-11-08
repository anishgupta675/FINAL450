//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
public class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n;
                    n = sc.nextInt();
                    ArrayList<String> arr = new ArrayList<String>();
                    for(int i = 0;i<n;i++)
                        {
                            String p = sc.next();
                            arr.add(p);
                        }
                    String line = sc.next();
                    Sol obj = new Sol();  
                    System.out.println(obj.wordBreak(line,arr));  
                    
                }
        }
}
// } Driver Code Ends


//User function Template for Java

class Sol
{
    public static int wordBreak(String A, ArrayList<String> B )
    {
        //code here
        int[] dp = new int[A.length() + 1];
        dp[0] = 1;
        for(int i = 0; i <= A.length(); i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] == 1 && B.contains(A.substring(j, i))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[A.length()];
    }
}