//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            String s = read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.lps(s));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    int lps(String s) {
        // code here
        int start = 0;
        int end = 1;
        int[] store = new int[s.length()];
    
        while( end < s.length() ){
        
            if( s.charAt(start) == s.charAt(end) ){
                store[end] = start+1;
                start+=1;
                end+=1;
            }
            else{
            
                if( start == 0){
                    store[end] = 0;
                    end=end+1;
                }else{
                    start = store[start-1];
                }
            }
        }
        
        return store[s.length()-1];
    }
}