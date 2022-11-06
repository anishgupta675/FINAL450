//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            int[] nums = new int[n];
            String[] S = br.readLine().trim().split(" ");
            for(int i = 0; i < n; i++)
                nums[i]  =Integer.parseInt(S[i]);
            int k = Integer.parseInt(br.readLine().trim());
            Solution obj = new Solution();
            System.out.println(obj.solveWordWrap(nums, k));
        }
    }
}

// } Driver Code Ends


class Solution
{
    public int solveWordWrap (int[] arr, int k)
    {
        // Code here 
        int[][] dp = new int[k+1][arr.length];
       for( int[] row : dp){
          Arrays.fill(row,Integer.MAX_VALUE);
       }
      
      
      int result =  minwordwrap( arr , 0 , k  , 0 , k , dp);
      return result;
    }
    
    public int minwordwrap( int[] arr , int index , int remainingspace , int result , int k , int[][] dp ){
        
        if( index == arr.length){ 
            return result ;
        }
        
        
        int min = Integer.MAX_VALUE;
        
        if( dp[remainingspace][index] != Integer.MAX_VALUE){
            min = result + dp[remainingspace][index];
            return min;
        }
        
        if( remainingspace == k){
            
            min = minwordwrap( arr , index+1 , remainingspace-arr[index] , result , k , dp);
            
        }else if( remainingspace >= arr[index]+1){
            
            int left = remainingspace - (arr[index]+1);
            
            int added = minwordwrap( arr , index+1 , left , result , k , dp);
            
            int notadded = minwordwrap( arr , index+1 , k-arr[index] ,(remainingspace*remainingspace)+result , k , dp );
            
            min = Math.min( added , notadded );
        }
        else{
            min = minwordwrap( arr,index+1 ,k-arr[index], (remainingspace*remainingspace)+result ,k , dp);
        }
        
        dp[remainingspace][index] = min-result;
        
        return min;
    }
}