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
    long mod=1000000007;
    long solve(String s,int i,int j,Long dp[][])
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=null)
        {
            return dp[i][j];
        }
        if(i==j)
        {
            return dp[i][j]=(long)1;
        }
        else if(s.charAt(i)==s.charAt(j))
        {
            return dp[i][j]=(1+solve(s,i+1,j,dp)%mod+solve(s,i,j-1,dp)%mod)%mod;
        }
        return dp[i][j]=(mod+solve(s,i+1,j,dp)%mod+solve(s,i,j-1,dp)%mod-solve(s,i+1,j-1,dp)%mod)%mod;
    }
    long countPS(String str)
    {
        // Your code here
        Long[][] dp=new Long[str.length()][str.length()];
        return solve(str,0,str.length()-1,dp);
    }
}