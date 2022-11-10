//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String roman = br.readLine().trim();
            Solution ob = new Solution();
            System.out.println(ob.romanToDecimal(roman));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    private int getInteger(char ch) {
        if(ch == 'I') return 1;
        if(ch == 'V') return 5;
        if(ch == 'X') return 10;
        if(ch == 'L') return 50;
        if(ch == 'C') return 100;
        if(ch == 'D') return 500;
        return 1000;
    }
    // Finds decimal value of a given roman numeral
    public int romanToDecimal(String str) {
        // code here
        if(str.length() == 1) return getInteger(str.charAt(0));
        int res = 0;
        for(int i = 0; i < str.length(); i++) {
            if(i + 1 < str.length()) {
                if(getInteger(str.charAt(i)) >= getInteger(str.charAt(i + 1))) res+= getInteger(str.charAt(i));
                else {
                    res+= getInteger(str.charAt(i + 1)) - getInteger(str.charAt(i));
                    i++;
                }
            } else res+= getInteger(str.charAt(i));
        }
        return res;
    }
}