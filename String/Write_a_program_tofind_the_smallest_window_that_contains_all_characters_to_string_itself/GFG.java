//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            String str = br.readLine();
            
            Solution obj = new Solution();
            System.out.println(obj.findSubString(str));
            
        }
	}
}


// } Driver Code Ends


//User function Template for Java

class Solution {
    public int findSubString( String str) {
        // Your code goes here
        int length = str.length();

        HashSet<Character> set = new HashSet<>();

        for(int i=0; i<str.length(); i++){

            set.add(str.charAt(i));

        }

        int l=0, r=0, count = 0;

        HashMap<Character,Integer> hm = new HashMap<>();

        while(r<str.length()){

            char ch = str.charAt(r);

            hm.put(ch, hm.getOrDefault(ch,0)+1);

            if(hm.get(ch)==1)

                count++;

            while(count==set.size()){

                int n = r-l+1;

                length = Math.min(length, n);

                

                char c = str.charAt(l);

                hm.put(c,hm.get(c)-1);

                if(hm.get(c)==0)

                    count--;

                l++;    

            }

            r++;

        }

        return length;
    }
}