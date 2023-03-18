package Searching_Sorting.Missing_Number_in_AP;

//{ Driver Code Starts
//Initial Template for Java

import java.io.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String arr[] = in.readLine().trim().split("\\s+");
            int A = Integer.parseInt(arr[0]);
            int B = Integer.parseInt(arr[1]);
            int C = Integer.parseInt(arr[2]);
            
            out.println(Solution.inSequence(A, B, C));
        }
        out.close();
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int inSequence(int A, int B, int C){
        // code here
        if(A == B) return 1;
        if(C == 0) return 0;
        if((B - A) % C == 0 && (B - A) / C > 0) return 1;
        return 0;
    }
}