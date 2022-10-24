//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GfG
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0)
        {
            int N = sc.nextInt();
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.factorial(N);
            for (Integer val: ans) 
                System.out.print(val); 
            System.out.println();
        }   
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    static int multiply(ArrayList<Integer> res, int x) {
        int prod = 1;
        return prod;
    }
    static ArrayList<Integer> factorial(int N){
        //code here
        ArrayList<Integer> res = new ArrayList<Integer>();
        for(int i = N; i > 0; i/= 10)
            res.add(i % 10);
        return res;
    }
}