package Searching_Sorting.Maximum_and_minimum_of_an_array_using_minimum_number_of_comparisons;

//{ Driver Code Starts
//Initial Template for Java

import java.io.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String[] S = read.readLine().split(" ");
            int A=Integer.parseInt(S[0]);
            int B=Integer.parseInt(S[1]);
            int C=Integer.parseInt(S[2]);
            Solution ob = new Solution();
            System.out.println(ob.middle(A,B,C));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    int middle(int A, int B, int C){
        //code here
        return (A + B + C) - (Math.max(A, Math.max(B, C)) + Math.min(A, Math.min(B, C)));
    }
}