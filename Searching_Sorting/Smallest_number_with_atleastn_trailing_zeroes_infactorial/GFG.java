//{ Driver Code Starts
//Initial Template for Java

import java.util.*;

public class GFG
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        
        while (t-- > 0)
        {
            int n = sc.nextInt();
            
            System.out.println(new Solution().findNum(n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java


class Solution
{
    
    private int appendZeroes(int n) {
        int s = 0;
        while(n >= 5) {
            s+= (n / 5);
            n/= 5;
        }
        return s;
    }
    
    public int findNum(int n)
    {
        //complete the function here
        int low = 1, high = 5 * n, mid;
        while(low <= high) {
            mid = low + ((high - low) >> 1);
            if(appendZeroes(mid) == n && mid % 5 == 0) return mid;
            else if(appendZeroes(mid) < n) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};