//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.stream.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int n = Integer.parseInt(in.readLine());
            String arr[] = in.readLine().trim().split("\\s+");
            List<String> dict = new ArrayList<String>();
            for(int i = 0;i < n;i++)
                dict.add(arr[i]);
            String s = in.readLine();
            
            Solution ob = new Solution();
            List<String> ans = new ArrayList<String>();
            ans = ob.wordBreak(n, dict, s);
            if(ans.size() == 0)
                System.out.println("Empty");
            else{
                List<String> sol = ans.stream().sorted().collect(Collectors.toList());
                for(int i = 0;i < sol.size();i++)
                    System.out.print("("+sol.get(i)+")");
                System.out.println();
            }
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    private static List<String> res = new ArrayList<String>();
    private static void breakWord(int n, int idx, List<String> dict, String s, String data) {
        if(idx >= n) {
            res.add(data);
            return;
        }
        for(int i = 0; i < dict.size(); i++) if(dict.get(i).equals(s.substring(idx, idx + dict.get(i).length()))) breakWord(n, idx + dict.get(i).length(), dict, s, data + dict.get(i));
    }
    static List<String> wordBreak(int n, List<String> dict, String s)
    {
        // code here
        breakWord(n, 0, dict, s, "");
        return res;
    }
}