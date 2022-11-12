//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;


// } Driver Code Ends
//User function Template for Java

class Solution {
    private static int[] getLPS(String str) {
        int prevLPS = 0, i = 1;
        int[] lps = new int[str.length()];
        while(i < str.length()) {
            if(str.charAt(prevLPS) == str.charAt(i)) lps[i++] = ++prevLPS;
            else {
                if(prevLPS == 0)
                    lps[i++] = 0;
                else prevLPS = lps[prevLPS - 1];
            }
        }
        return lps;
    }
    public static int minChar(String str) {
       //Write your code here
       StringBuilder s = new StringBuilder();
       s.append(str);
       String rev = s.reverse().toString();
       s.reverse().append('$').append(rev);
       int[] lps = getLPS(s.toString());
       return str.length() - lps[s.length() - 1];
    }
}

//{ Driver Code Starts.

class GFG {
	public static void main(String[] args) throws IOException
	{
	    var sc = new FastReader();
	    int test = sc.nextInt();
	    while(test-->0){
    		String s = sc.nextString();
    		System.out.println(Solution.minChar(s));
	    }
	}
    
    public static class FastReader
	{
		BufferedReader br;
		StringTokenizer st;

		public FastReader()
		{
			br = new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer("");
		}

		private void read() throws IOException
		{
			st = new StringTokenizer(br.readLine());
		}

		public String nextString() throws IOException
		{
			while(!st.hasMoreTokens())
				read();
			return st.nextToken();
		}

		public int nextInt() throws IOException
		{
			return Integer.parseInt(nextString());
		}

		public long nextLong() throws IOException
		{
			return Long.parseLong(nextString());
		}
	}
}
// } Driver Code Ends