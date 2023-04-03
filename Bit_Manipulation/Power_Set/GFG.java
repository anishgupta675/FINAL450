//{ Driver Code Starts
//Initial Template for Java

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
            String s = br.readLine().trim();
            Solution ob = new Solution();
            List<String> ans = ob.AllPossibleStrings(s);
            for(String i: ans)
                System.out.print(i + " ");
            System.out.println();
            
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    public List<String> AllPossibleStrings(String s)
    {
        // Code here
        List<String> res = new ArrayList<String>();
		for(int mask = 0; mask < (1 << s.length()); mask++) {
		    String data = "";
		    for(int i = 0; i < s.length(); i++) if((mask & (1 << i)) != 0) data+= s.charAt(i);
		    if(!data.equals("")) res.add(data.replaceAll("\\s", ""));
		}
		Collections.sort(res);
		return res;
    }
}