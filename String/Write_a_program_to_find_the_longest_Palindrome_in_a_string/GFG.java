//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String S = read.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.longestPalin(S));
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution{
    static String longestPalin(String str){
        // code here
        int n = str.length(); 
        if(n == 1) return str;
        if (n == 2)
            return (str.charAt(0) == str.charAt(1)) ? str : str.substring(0, 1);
                  
                  
  
        int maxLength = 1,start=0;
        int low, high;
        for (int i = 0; i < n; i++) {
            low = i - 1;
            high = i + 1;
            while ( high < n && str.charAt(high) == str.charAt(i)) 
                high++;
        
            while ( low >= 0 && str.charAt(low) == str.charAt(i)) 
                low--;
        
            while (low >= 0 && high < n && str.charAt(low) == str.charAt(high) ){ 
                low--;
                high++;
            }
  
            int length = high - low - 1;
            if (maxLength < length){
                maxLength = length;
                start=low+1;
            }
        }
        return str.substring(start, start + maxLength);
    }
}