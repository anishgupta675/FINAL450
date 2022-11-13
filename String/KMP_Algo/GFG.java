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
    int[] getLPS(String s) {
        int prevLPS = 0, i = 1;
        int[] lps = new int[s.length()];
        while(i < s.length()) {
            if(s.charAt(prevLPS) == s.charAt(i)) lps[i++] = ++prevLPS;
            else {
                if(prevLPS == 0) lps[i++] = 0;
                else prevLPS = lps[prevLPS - 1];
            }
        }
        return lps;
    }
    int lps(String s) {
        // code here
        int[] lps = getLPS(s);
        return lps[s.length() - 1];
    }
}